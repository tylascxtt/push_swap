/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenaya <mabenaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:13:43 by mabenaya          #+#    #+#             */
/*   Updated: 2026/01/17 15:30:59 by mabenaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	int				index;
}	t_list;

typedef struct s_var
{
	char	*str;
	char	**number;
	int		i;
	int		j;
	int		*nums;
	int		chunk;
	int		midchunk;
	int		origin_chunk;
	t_list	*list;
}	t_var;

typedef struct s_extra
{
	int	pos;
	int	maxindex;
	int	mid;
}	t_extra;

size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char *charset);
long	ft_atoi(char *str, t_var *a);

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);

t_list	*parse_args(int argc, char **argv);

t_list	*lower_num(t_list *stack);
t_list	*higher_num(t_list *stack);
t_list	*second_higher_num(t_list *stack);
int		issep(char s, char *sep);

void	rotate(t_list **stack, char type);
void	reverse_rotate(t_list **stack, char type);
void	swap(t_list **stack, char type);
void	push(t_list **from, t_list **to, char type);
void	rr(t_list **stack_a, t_list **stack_b);

void	sort_check(t_list **stack_a, t_list **stack_b);
void	ft_start(t_list **stack_a, t_list **stack_b);
void	sort_of_three(t_list **stack);
void	sort_of_four(t_list **stack_a, t_list **stack_b);
void	sort_of_five(t_list **stack_a, t_list **stack_b);
void	chunk(t_list **stack_a, t_list **stack_b, int range);
void	sort_chunk(t_list **stack_a, t_list **stack_b);
int		position_finder(t_list *stack, int index);

int		*list_to_array(t_list *a, int n);
void	sort_arr(int *tab, int size);
int		find_pos(int *sorted, int n, int value);
void	assign_indexes(t_list *stack);
void	exits(t_var *a);
void	error_exit(void);

#endif