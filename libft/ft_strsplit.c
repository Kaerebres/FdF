/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:55:36 by csimon            #+#    #+#             */
/*   Updated: 2016/11/15 20:55:38 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int		ft_wordcount(char const *s, char c)
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

static int		ft_wordlen(char const *s, char c, int index)
{
	int		wordlen;

	wordlen = 0;
	while (s[index] == c)
		index += 1;
	while (s[index] != c && s[index] != '\0')
	{
		index += 1;
		wordlen++;
	}
	return (wordlen);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word;
	int		index;
	int		index2;

	index2 = 0;
	index = 0;
	word = 0;
	if (!s)
		return (tab = (char**)&s);
	if ((tab = (char**)malloc(sizeof(char*) * ft_wordcount(s, c) + 1)) == NULL)
		return (NULL);
	while (s[index] != '\0' && word < ft_wordcount(s, c))
	{
		while (s[index] == c)
			index++;
		if ((tab[word] = (char*)malloc(ft_wordlen(s, c, index) + 1)) == NULL)
			return (NULL);
		while (s[index] != c && s[index] != '\0')
			tab[word][index2++] = s[index++];
		tab[word++][index2] = '\0';
		index2 = 0;
	}
	tab[word] = 0;
	return (tab);
}
