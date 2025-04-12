/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:48:31 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/12 15:32:29 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef enum e_action
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_action;

typedef enum e_stack_id
{
	A,
	B
}	t_stack_id;

typedef struct s_stack
{
	char			*argv;
	unsigned int	index;
	long int		value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	size;
}	t_stacks;

void		init_stacks(t_stacks *stack, int argc, char *argv[]);
bool		parser(t_stack *a);
bool		has_duplicates(t_stack *a);
void		assign_sorted_index(t_stack *a);
void		clear_program(t_stacks *stack, char *str, int exit_code);

t_stack		*new_stack(char *argv, long int value);
int			stack_size(t_stack *stack);
t_stack		*last_stack(t_stack *stack);
void		stack_addback(t_stack **stack, t_stack *new);

void		swap(t_stack **a, t_stack **b, t_action action);
void		push(t_stack **a, t_stack **b, t_action action);
void		rotate(t_stack **a, t_stack **b, t_action action);
void		rev_rotate(t_stack **a, t_stack **b, t_action action);
void		push_swap(t_stack **a, t_stack **b, t_action action, bool checker);

bool		is_sorted(t_stack *a);
void		print_action(t_action action);
t_stack		*find_min(t_stack *stack);
t_stack		*find_max(t_stack *stack);
int			find_position(t_stack *stack, t_stack *target);
void		bring_to_top(t_stack **stack, t_stack *target, t_stack_id id);
void		sort_two(t_stack **a, t_stack **b);
void		sort_three(t_stack **a, t_stack **b);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
void		tiny_sort(t_stacks *stack);
void		butterfly_sort(t_stacks *stack);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		execute_action(t_stacks *stack, char *action);

long		ft_atol(char *ptr);
char		*ft_strdup(char *src);
char		**ft_split(char *s, char sep);
void		free_matrix_2d(void **matrix);

#endif