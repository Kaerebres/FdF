/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:28:01 by csimon            #+#    #+#             */
/*   Updated: 2017/04/19 11:28:02 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int		ft_wordcount(char *s, char c)
{
	int		counter;
	int		index;

	index = 0;
	counter = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] != c && s[index] != '\0')
			counter++;
		while (s[index] != c && s[index] != '\0')
			index++;
	}
	return (counter);
}

int				check_line(char *line)
{
	static int	x = 0;
	int			y;

	y = 0;
	if (x == 0)
	{
		x = ft_wordcount(line, ' ');
		return (x == 0 ? 1 : 0);
	}
	if (x != 0)
		y = ft_wordcount(line, ' ');
	return ((y == x || y == 0) ? 0 : 1);
}

void			ft_error(int code)
{
	if (code == 0)
		ft_putstr("No input file.\n");
	if (code == 1)
		ft_putstr("Failed to open file.\n");
	if (code == 2)
		ft_putstr("Invalid file format.\n");
	if (code == 3)
		ft_putstr("Empty file.\n");
	exit(0);
}
