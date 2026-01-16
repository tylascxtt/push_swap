/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:55:46 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/16 20:37:12 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../mandatory/push_swap.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_inst
{
	char	*name;
	void	(*op)(t_list **s);
	int		stack_flag;
}	t_inst;

void	exec_inst(char *line, t_list **a, t_list **b, const t_inst *ops);
int		is_sorted(t_list *a);
// void	error_exit(void);
void	rotatee(t_list **stack);
void	rr_bonus(t_list **stack_a, t_list **stack_b);
void	swapp(t_list **stack);
void	reverse_rotatee(t_list **stack);
void	pushh(t_list **from, t_list **to);
char	*get_next_line(int fd);

#endif