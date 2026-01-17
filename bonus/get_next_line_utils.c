/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:54:53 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/17 15:51:36 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "checker.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	length;

	if (!s)
		return (0);
	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	if (size == 0)
		return (ft_strlen_gnl(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen_gnl(src));
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*dup;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen_gnl(s1);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, len + 1);
	return (dup);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (s1);
	result = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!result)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (free(s1), result);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen_gnl(s);
	if (start >= s_len)
		return (ft_strdup_gnl(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
