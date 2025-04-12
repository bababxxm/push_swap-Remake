/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:05:15 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/12 15:03:27 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char		*action;
	t_stacks	stack;

	init_stacks(&stack, argc, argv);
	action = get_next_line(0);
	while (action)
	{
		execute_action(&stack, action);
		printf("%s", action);
		free(action);
		action = get_next_line(0);
	}
	if (!is_sorted(stack.a))
		clear_program(&stack, "KO", EXIT_SUCCESS);
	else if (is_sorted(stack.a))
		clear_program(&stack, "OK", EXIT_SUCCESS);
}

void	execute_action(t_stacks *stack, char *action)
{
	if (!ft_strncmp(action, "sa\n", 3))
		push_swap(&stack->a, &stack->b, SA, true);
	else if (!ft_strncmp(action, "sb\n", 3))
		push_swap(&stack->a, &stack->b, SB, true);
	else if (!ft_strncmp(action, "pa\n", 3))
		push_swap(&stack->a, &stack->b, PA, true);
	else if (!ft_strncmp(action, "pb\n", 3))
		push_swap(&stack->a, &stack->b, PB, true);
	else if (!ft_strncmp(action, "ra\n", 3))
		push_swap(&stack->a, &stack->b, RA, true);
	else if (!ft_strncmp(action, "rb\n", 3))
		push_swap(&stack->a, &stack->b, RB, true);
	else if (!ft_strncmp(action, "rr\n", 3))
		push_swap(&stack->a, &stack->b, RR, true);
	else if (!ft_strncmp(action, "rra\n", 4))
		push_swap(&stack->a, &stack->b, RRA, true);
	else if (!ft_strncmp(action, "rrb\n", 4))
		push_swap(&stack->a, &stack->b, RRB, true);
	else if (!ft_strncmp(action, "rrr\n", 4))
		push_swap(&stack->a, &stack->b, RRR, true);
	else
		clear_program(stack, "Error", EXIT_FAILURE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
