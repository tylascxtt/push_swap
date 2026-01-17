/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:14:01 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/17 15:55:02 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

t_list	*lower_num(t_list *stack)
{
	t_list	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->num < min->num)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*higher_num(t_list *stack)
{
	t_list	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->num > max->num)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_list	*second_higher_num(t_list *stack)
{
	t_list	*max;
	t_list	*second_max;
	int		max_val;

	if (!stack || !stack->next)
		return (NULL);
	max = higher_num(stack);
	max_val = max->num;
	second_max = NULL;
	while (stack)
	{
		if (stack->num != max_val)
		{
			if (!second_max || stack->num > second_max->num)
				second_max = stack;
		}
		stack = stack->next;
	}
	return (second_max);
}

int	issep(char s, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (s == sep[i])
			return (1);
		i++;
	}
	return (0);
}
