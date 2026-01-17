/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:14:04 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/15 13:41:25 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_finder(t_list *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static void	smallopti(t_list **stack_a, t_list **stack_b, int maxindex)
{
	t_list	*second_high;

	if (!(*stack_b))
		return ;
	second_high = second_higher_num((*stack_b));
	if ((*stack_b) == second_high)
	{
		if (!(*stack_a) || (*stack_a)->index > maxindex)
		{
			push(stack_b, stack_a, 'a');
		}
	}
}

void	sort_chunk(t_list **stack_a, t_list **stack_b)
{
	t_extra	vars;

	while ((*stack_b))
	{
		vars.maxindex = higher_num((*stack_b))->index;
		while ((*stack_b) && (*stack_b)->index != vars.maxindex)
		{
			smallopti(stack_a, stack_b, vars.maxindex);
			if ((*stack_b) && (*stack_b)->index != vars.maxindex)
			{
				vars.mid = ft_lstsize((*stack_b)) / 2;
				vars.pos = position_finder((*stack_b), vars.maxindex);
				if (vars.pos <= vars.mid)
					rotate(stack_b, 'b');
				else
					reverse_rotate(stack_b, 'b');
			}
		}
		if ((*stack_b))
		{
			push(stack_b, stack_a, 'a');
			if ((*stack_a)->next && (*stack_a)->index > (*stack_a)->next->index)
				swap(stack_a, 'a');
		}
	}
}

void	chunk(t_list **stack_a, t_list **stack_b, int div)
{
	t_var	var;

	var.i = 0;
	var.origin_chunk = ft_lstsize((*stack_a)) / div;
	var.chunk = var.origin_chunk;
	var.midchunk = var.chunk / 2;
	while ((*stack_a))
	{
		while ((*stack_a)->index >= var.chunk)
			rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
		if ((*stack_b)->next && (*stack_b)->index >= var.midchunk)
		{
			if ((*stack_a) && (*stack_a)->index >= var.chunk)
				rr(stack_a, stack_b);
			else
				rotate(stack_b, 'b');
		}
		if (++var.i >= var.chunk)
		{
			var.chunk += var.origin_chunk;
			var.midchunk += var.origin_chunk;
		}
	}
	sort_chunk(stack_a, stack_b);
}
