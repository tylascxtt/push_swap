/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:13:29 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/17 12:51:13 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = parse_args(argc, argv);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	assign_indexes(stack_a);
	sort_check(&stack_a, &stack_b);
	if (stack_b)
		ft_lstclear(&stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
