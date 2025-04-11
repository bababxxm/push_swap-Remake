/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:48:31 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/11 04:50:46 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

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

// printf
void	print_stacks(t_stacks *stack);

// stack
t_stack	*new_stack(char *argv, long int value);
int		stack_size(t_stack *stack);
t_stack	*last_stack(t_stack *stack);
void	stack_addback(t_stack **stack, t_stack *new);

// action
void	swap(t_stack **a, t_stack **b, t_action action);
void	push(t_stack **a, t_stack **b, t_action action);
void	rotate(t_stack **a, t_stack **b, t_action action);
void	rev_rotate(t_stack **a, t_stack **b, t_action action);
void	push_swap(t_stack **a, t_stack **b, t_action action);

// sort
void	tiny_sort(t_stacks *stack);

// utils
long	ft_atol(char *ptr);
char	*ft_strdup(char *src);
char	**ft_split(char *s, char sep);
bool	has_duplicates(t_stack *stack);
void	free_matrix_2D(void **matrix);
bool	is_sorted(t_stack *a);
void	put_action(t_action action);

#endif