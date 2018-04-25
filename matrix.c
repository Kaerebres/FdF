/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:33:15 by csimon            #+#    #+#             */
/*   Updated: 2017/04/19 10:33:18 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_around_x(float angle, t_point *begin)
{
	t_point *tmp;
	float	x;
	float	y;
	float	multrix[3][3];

	multrix[0][0] = 1;
	multrix[0][1] = 0;
	multrix[0][2] = 0;
	multrix[1][0] = 0;
	multrix[1][1] = cos(angle);
	multrix[1][2] = sin(angle);
	multrix[2][0] = 0;
	multrix[2][1] = -sin(angle);
	multrix[2][2] = cos(angle);
	tmp = begin;
	while (tmp != NULL)
	{
		x = tmp->x;
		y = tmp->y;
		tmp->x = x * multrix[0][0] + y * multrix[1][0] + tmp->z * multrix[2][0];
		tmp->y = x * multrix[0][1] + y * multrix[1][1] + tmp->z * multrix[2][1];
		tmp->z = x * multrix[0][2] + y * multrix[1][2] + tmp->z * multrix[2][2];
		tmp = tmp->next;
	}
}

void	rotate_around_y(float angle, t_point *begin)
{
	t_point *tmp;
	float	x;
	float	y;
	float	multrix[3][3];

	multrix[0][0] = cos(angle);
	multrix[0][1] = 0;
	multrix[0][2] = -sin(angle);
	multrix[1][0] = 0;
	multrix[1][1] = 1;
	multrix[1][2] = 0;
	multrix[2][0] = sin(angle);
	multrix[2][1] = 0;
	multrix[2][2] = cos(angle);
	tmp = begin;
	while (tmp != NULL)
	{
		x = tmp->x;
		y = tmp->y;
		tmp->x = x * multrix[0][0] + y * multrix[1][0] + tmp->z * multrix[2][0];
		tmp->y = x * multrix[0][1] + y * multrix[1][1] + tmp->z * multrix[2][1];
		tmp->z = x * multrix[0][2] + y * multrix[1][2] + tmp->z * multrix[2][2];
		tmp = tmp->next;
	}
}

void	rotate_around_z(float angle, t_point *begin)
{
	t_point *tmp;
	float	x;
	float	y;
	float	multrix[3][3];

	multrix[0][0] = cos(angle);
	multrix[0][1] = sin(angle);
	multrix[0][2] = 0;
	multrix[1][0] = -sin(angle);
	multrix[1][1] = cos(angle);
	multrix[1][2] = 0;
	multrix[2][0] = 0;
	multrix[2][1] = 0;
	multrix[2][2] = 1;
	tmp = begin;
	while (tmp != NULL)
	{
		x = tmp->x;
		y = tmp->y;
		tmp->x = x * multrix[0][0] + y * multrix[1][0] + tmp->z * multrix[2][0];
		tmp->y = x * multrix[0][1] + y * multrix[1][1] + tmp->z * multrix[2][1];
		tmp->z = x * multrix[0][2] + y * multrix[1][2] + tmp->z * multrix[2][2];
		tmp = tmp->next;
	}
}

void	center_object(t_point *begin)
{
	t_point *tmp;
	float	max_x;
	float	max_y;

	max_x = 0;
	max_y = 0;
	tmp = begin;
	while (tmp != NULL)
	{
		if (tmp->x > max_x)
			max_x = tmp->x;
		if (tmp->y > max_y)
			max_y = tmp->y;
		tmp = tmp->next;
	}
	tmp = begin;
	max_x = 1500 / max_x;
	max_y = 1500 / max_y;
	while (tmp != NULL)
	{
		tmp->x = tmp->x * (max_x / 2 + 0.2) + 200;
		tmp->y = tmp->y * (max_y / 2) + 200;
		tmp = tmp->next;
	}
}
