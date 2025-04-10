/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:48:31 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/10 21:54:11 by sklaokli         ###   ########.fr       */
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
	long int		value;
	char			*argv;
	struct s_stack	*next;
}	t_stack;

// printf
void	print_stacks(t_stack *a, t_stack *b);

long	ft_atol(char *ptr);
char	*ft_strdup(char *src);
char	**ft_split(char *s, char sep);
void	free_matrix_2D(void **matrix);
t_stack	*new_stack(char *argv, long int value);
t_stack	*last_stack(t_stack *stack);
void	stack_addback(t_stack **stack, t_stack *new);
bool	has_duplicates(t_stack *stack, int value);
void	swap(t_stack **a, t_stack **b, t_action action);
void	push(t_stack **a, t_stack **b, t_action action);
void	rotate(t_stack **a, t_stack **b, t_action action);
void	rev_rotate(t_stack **a, t_stack **b, t_action action);
void	push_swap(t_stack **a, t_stack **b, t_action action);

#endif