/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:13:46 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/17 14:55:52 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exits(t_var *var)
{
	int	i;

	write(2, "Error\n", 6);
	ft_lstclear(&var->list);
	if (var->number)
	{
		i = 0;
		while (var->number[i])
			free(var->number[i++]);
		free(var->number);
	}
	exit(1);
}

void	free_split(char **sp)
{
	size_t	i;

	if (!sp)
		return ;
	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
}

static int	is_dup(t_list *a, int v)
{
	while (a)
	{
		if (a->num == v)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	process_number(char *num_str, t_var *var, char **numbers)
{
	long	n;
	t_list	*node;

	n = ft_atoi(num_str, var);
	if (n < INT_MIN || n > INT_MAX)
		(free_split(numbers), ft_lstclear(&var->list), error_exit());
	if (is_dup(var->list, (int)n))
		(free_split(numbers), ft_lstclear(&var->list), error_exit());
	node = ft_lstnew((int)n);
	if (!node)
		(free_split(numbers), ft_lstclear(&var->list), error_exit());
	ft_lstadd_back(&var->list, node);
}

t_list	*parse_args(int argc, char **argv)
{
	t_var	var;
	size_t	i;

	if (argc <= 1)
		return (NULL);
	var.str = NULL;
	var.i = 1;
	while (var.i < argc)
	{
		var.str = ft_strjoin(var.str, argv[var.i]);
		if (!var.str)
			error_exit();
		var.i++;
	}
	if (!var.str)
		error_exit();
	var.number = ft_split(var.str, " \t\r\n\v\f\a\b");
	free(var.str);
	var.list = NULL;
	i = 0;
	while (var.number[i])
		process_number(var.number[i++], &(var), var.number);
	free_split(var.number);
	return (var.list);
}
