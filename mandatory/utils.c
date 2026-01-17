/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:13:34 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/15 13:46:38 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *s1)
{
	size_t		i;
	size_t		lent;
	char		*dest;

	i = 0;
	lent = ft_strlen(s1);
	dest = (char *)malloc(lent + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)(s + start)))
		len = ft_strlen((char *)(s + start));
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*all;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	all = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!all)
		return (NULL);
	while (s1[++i])
		all[j++] = s1[i];
	all[j] = ' ';
	j++;
	i = -1;
	while (s2[++i])
		all[j++] = s2[i];
	all[j] = 0;
	free(s1);
	return (all);
}

static long	no_overflow(int sign, unsigned long long n, int count)
{
	if ((n > LLONG_MAX || count > 19) && sign == -1)
		(write(2, "Error\n", 6), exit(1));
	if ((n > LLONG_MAX || count > 19) && sign == 1)
		(write(2, "Error\n", 6), exit(1));
	return (n * sign);
}

long	ft_atoi(char *str, t_var *a)
{
	int		i;
	int		count;
	int		sign;
	long	n;

	i = 0;
	count = 0;
	sign = 1;
	n = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	if (str[i] == '\0' || str[i] < '0' || str[i] > '9')
		(exits(a));
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			(exits(a));
		n = (n * 10) + (str[i++] - '0');
		count++;
	}
	return (no_overflow(sign, n, count));
}
