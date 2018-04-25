/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:14:56 by csimon            #+#    #+#             */
/*   Updated: 2017/03/07 21:14:58 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# define PI 3.14159265358979323846

typedef	struct		s_point
{
	float			x;
	float			y;
	float			z;

	struct s_point	*next;
}					t_point;

int					get_next_line(const int fd, char **line);
void				rotate_around_x(float angle, t_point *begin);
void				rotate_around_y(float angle, t_point *begin);
void				rotate_around_z(float angle, t_point *begin);
void				center_object(t_point *begin);
void				displayit(t_point *begin, int max_y, int max_x);
int					check_line(char *line);
void				ft_error(int code);
#endif
