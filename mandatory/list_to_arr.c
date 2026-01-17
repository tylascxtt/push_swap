/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:13:54 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/15 13:40:26 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	*list_to_array(t_list *a, int n)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * n);
	if (!arr)
		error_exit();
	i = 0;
	while (i < n)
	{
		if (!a)
			error_exit();
		arr[i] = a->num;
		a = a->next;
		i++;
	}
	return (arr);
}

void	sort_arr(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_pos(int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indexes(t_list *stack)
{
	int		*sorted;
	int		size;
	t_list	*tmp;

	if (!stack)
		return ;
	size = ft_lstsize(stack);
	sorted = list_to_array(stack, size);
	sort_arr(sorted, size);
	tmp = stack;
	while (tmp)
	{
		tmp->index = find_pos(sorted, size, tmp->num);
		tmp = tmp->next;
	}
	free(sorted);
}
