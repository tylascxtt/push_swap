/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:13:58 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/17 15:30:02 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

void	ministrncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	countword(char *str, char *sep)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 1;
	while (str[i])
	{
		if (!issep(str[i], sep))
		{
			if (word)
				count++;
			word = 0;
		}
		else
			word = 1;
		i++;
	}
	return (count);
}

void	ffree_split(char **arr, int used)
{
	int	i;

	i = 0;
	while (i < used)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	fill_array_with_words(char **arr, char *str, char *seps)
{
	int	i;
	int	words;
	int	start;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!issep(str[i], seps))
		{
			start = i;
			while (str[i] && !issep(str[i], seps))
				i++;
			arr[words] = malloc(i - start + 1);
			if (!arr[words])
				return (words);
			ministrncpy(arr[words], str + start, i - start);
			words++;
		}
		else
			i++;
	}
	arr[words] = NULL;
	return (-1);
}

char	**ft_split(char *str, char *charset)
{
	int		cw;
	char	**split;
	int		fail_at;

	if (!str || !charset)
		return (NULL);
	cw = countword(str, charset);
	split = malloc((cw + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	fail_at = fill_array_with_words(split, str, charset);
	if (fail_at != -1)
	{
		ffree_split(split, fail_at);
		return (NULL);
	}
	return (split);
}
