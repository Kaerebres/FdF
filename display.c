/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:29:14 by csimon            #+#    #+#             */
/*   Updated: 2017/04/19 10:29:16 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_ft(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	else
	{
		ft_putstr("Keycode is ");
		ft_putnbr(keycode);
		ft_putstr("\n");
	}
	return (0);
}

int		*feed_linepoints(t_point *tmp, t_point *swap)
{
	int		*tab;

	tab = (int*)malloc(sizeof(int) * 4);
	tab[0] = tmp->x;
	tab[1] = tmp->y;
	tab[2] = swap->x;
	tab[3] = swap->y;
	return (tab);
}

void	plot_line(t_point *tmp, t_point *swap, void *mlx, void *win)
{
	int		d[4];
	int		err[2];
	int		*line;

	line = feed_linepoints(tmp, swap);
	d[0] = abs(line[2] - line[0]);
	d[2] = line[0] < line[2] ? 1 : -1;
	d[1] = -abs(line[3] - line[1]);
	d[3] = line[1] < line[3] ? 1 : -1;
	err[0] = d[0] + d[1];
	while (line[0] != line[2] || line[1] != line[3])
	{
		mlx_pixel_put(mlx, win, line[0], line[1], 0xFFFFFF);
		err[1] = 2 * err[0];
		if (err[1] >= d[1])
		{
			err[0] += d[1];
			line[0] += d[2];
		}
		if (err[1] <= d[0])
		{
			err[0] += d[0];
			line[1] += d[3];
		}
	}
}

t_point	*border_reach(t_point *tmp, int max_x)
{
	int		i;
	t_point *swap;

	swap = tmp;
	i = 0;
	while (i < max_x)
	{
		i++;
		if (swap->next == NULL)
			break ;
		swap = swap->next;
	}
	return (swap);
}

void	displayit(t_point *begin, int max_y, int max_x)
{
	void	*mlx;
	void	*win;
	int		count;
	t_point	*tmp;
	t_point *swap;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1500, 1500, "fdf");
	tmp = begin;
	count = 0;
	mlx_pixel_put(mlx, win, tmp->x, tmp->y, 0xFFFFFF);
	while (tmp->next != NULL)
	{
		if (tmp->x < tmp->next->x)
			plot_line(tmp, tmp->next, mlx, win);
		if (count < ((max_x) * (max_y - 1)))
		{
			swap = border_reach(tmp, max_x);
			plot_line(tmp, swap, mlx, win);
		}
		count++;
		tmp = tmp->next;
	}
	mlx_key_hook(win, my_key_ft, begin);
	mlx_loop(mlx);
}
