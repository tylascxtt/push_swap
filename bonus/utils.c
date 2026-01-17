/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:38:02 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/17 15:54:53 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotatee(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
}

void	swapp(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	reverse_rotatee(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = *stack;
	tmp->next = NULL;
	*stack = last;
}

void	pushh(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!(*from))
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
