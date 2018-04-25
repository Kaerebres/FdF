/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:27:11 by csimon            #+#    #+#             */
/*   Updated: 2017/04/19 10:27:13 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_and_display(t_point *begin, int max_y)
{
	t_point	*tmp;
	int		max_x;

	max_x = 0;
	tmp = begin;
	while (tmp != NULL)
	{
		if (tmp->y == 0)
			max_x++;
		tmp->x *= 2;
		tmp->x += 5;
		tmp->y *= 4;
		tmp->y += 5;
		tmp->z *= 16;
		tmp = tmp->next;
	}
	center_object(begin);
	rotate_around_x(PI / 4, begin);
	center_object(begin);
	rotate_around_y(-PI / 8, begin);
	center_object(begin);
	displayit(begin, max_y, max_x);
}

t_point	*add_one_elem(void)
{
	t_point		*elem;

	if ((elem = (t_point*)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	elem->next = NULL;
	return (elem);
}

t_point	*for_the_norm(t_point *tmp, int y_max, int x, char **tab_values)
{
	tmp->x = x;
	tmp->y = y_max;
	tmp->z = ft_atoi(tab_values[x]);
	return (tmp);
}

t_point	*feed_points(char **tab_values, int y_num)
{
	static t_point	*begin_l = NULL;
	t_point			*tmp;
	int				x;
	int				index;

	index = 0;
	x = 0;
	if (begin_l == NULL)
		begin_l = add_one_elem();
	tmp = begin_l;
	while (tab_values[index] != '\0')
		index++;
	while (x < index)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (x > 0 || y_num > 0)
		{
			tmp->next = add_one_elem();
			tmp = tmp->next;
		}
		tmp = for_the_norm(tmp, y_num, x, tab_values);
		x++;
	}
	return (begin_l);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_point	*start;
	int		y_num;
	char	*line;
	char	**tab_values;

	y_num = 0;
	if (argc < 2)
		ft_error(0);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		ft_error(1);
	while ((get_next_line(fd, &line)) > 0)
	{
		tab_values = ft_strsplit(line, ' ');
		if (check_line(line) != 0)
			ft_error(2);
		start = feed_points(tab_values, y_num);
		if (tab_values[0] != '\0')
			y_num++;
	}
	if (y_num == 0)
		ft_error(3);
	else
		rotate_and_display(start, y_num);
	return (0);
}
