/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:39:30 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/17 15:53:29 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"
#include "checker.h"

void	freeall(char *line, t_list **a, t_list **b)
{
	free(line);
	ft_lstclear(a);
	ft_lstclear(b);
}

void	exec_inst(char *line, t_list **a, t_list **b, const t_inst *ops)
{
	int	i;

	i = 0;
	while (ops[i].name)
	{
		if (!ft_strcmp(line, ops[i].name))
		{
			if (!ft_strcmp(ops[i].name, "pa\n"))
				pushh(b, a);
			else if (!ft_strcmp(ops[i].name, "pb\n"))
				pushh(a, b);
			else
			{
				if (ops[i].stack_flag & 1)
					ops[i].op(a);
				if (ops[i].stack_flag & 2)
					ops[i].op(b);
			}
			return ;
		}
		i++;
	}
	freeall(line, a, b);
	get_next_line(-1);
	error_exit();
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

void	run_checker(t_list **a, const t_inst *ops)
{
	t_list	*b;
	char	*line;

	b = NULL;
	line = get_next_line(0);
	while (line)
	{
		exec_inst(line, a, &b, ops);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (b)
		ft_lstclear(&b);
}

int	main(int argc, char **argv)
{
	t_list				*a;
	static const t_inst	ops[] = {
	{"sa\n", swapp, 1},
	{"sb\n", swapp, 2},
	{"ss\n", swapp, 3},
	{"pa\n", NULL, 0},
	{"pb\n", NULL, 0},
	{"ra\n", rotatee, 1},
	{"rb\n", rotatee, 2},
	{"rr\n", rotatee, 3},
	{"rra\n", reverse_rotatee, 1},
	{"rrb\n", reverse_rotatee, 2},
	{"rrr\n", reverse_rotatee, 3},
	{NULL, NULL, 0}
	};

	if (argc == 1)
		return (0);
	a = parse_args(argc, argv);
	run_checker(&a, ops);
	ft_lstclear(&a);
	get_next_line(-1);
	return (0);
}
