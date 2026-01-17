/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:13:40 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/13 16:44:19 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_of_three(t_list **stack)
{
	if ((*stack) == higher_num((*stack)))
		rotate(stack, 'a');
	else if ((*stack)->next == higher_num((*stack)))
		reverse_rotate(stack, 'a');
	if ((*stack)->num > (*stack)->next->num)
		swap(stack, 'a');
}

void	sort_of_four(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a) != lower_num((*stack_a)))
		reverse_rotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
	sort_of_three(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort_of_five(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a) != lower_num((*stack_a)))
	{
		if ((*stack_a)->next == lower_num((*stack_a)))
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'b');
	sort_of_four(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
}

void	ft_start(t_list **stack_a, t_list **stack_b)
{
	int	mode;

	mode = ft_lstsize(*stack_a);
	if (mode <= 3)
		sort_of_three(stack_a);
	else if (mode == 4)
		sort_of_four(stack_a, stack_b);
	else if (mode == 5)
		sort_of_five(stack_a, stack_b);
	else if (mode > 5 && mode <= 100)
		chunk(stack_a, stack_b, 5);
	else if (mode > 100 && mode <= 500)
		chunk(stack_a, stack_b, 11);
	else
		chunk(stack_a, stack_b, 15);
	ft_lstclear(stack_a);
}

void	sort_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (ft_start(stack_a, stack_b));
		tmp = tmp->next;
	}
	ft_lstclear(stack_a);
}
