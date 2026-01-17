/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:36:43 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/17 15:56:44 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*newline_finder(int fd, char *buff, char *strr)
{
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		if (buff && ft_strchr(buff, '\n'))
			break ;
		bytes = read(fd, strr, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buff), free(strr), buff = NULL);
		if (bytes == 0)
			break ;
		strr[bytes] = '\0';
		buff = ft_strjoin_free(buff, strr);
		if (!buff)
			return (free(strr), NULL);
	}
	free(strr);
	return (buff);
}

char	*getsline_fixbuff(char *line)
{
	char	*buff;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	buff = ft_substr_gnl(line, i + 1, ft_strlen_gnl(line) - i);
	if (!buff)
		return (free(line), NULL);
	if (line[i])
		line[i + 1] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		*strr;

	if (fd == -1)
		return (free(buff), buff = NULL, NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || (size_t)BUFFER_SIZE >= INT_MAX)
		return (NULL);
	strr = malloc(BUFFER_SIZE + 1);
	if (!strr)
		return (free(buff), buff = NULL);
	strr[0] = 0;
	line = newline_finder(fd, buff, strr);
	buff = NULL;
	if (!line)
		return (free(buff), NULL);
	buff = getsline_fixbuff(line);
	if (!line[0])
		return (free(buff), free(line), buff = NULL);
	return (line);
}
