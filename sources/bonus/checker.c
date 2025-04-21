/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:05:15 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/19 18:36:34 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	*input;
	t_data	stack;

	init_stack(&stack, argc, argv);
	input = get_next_line(0);
	while (input)
	{
		execute_action(&stack, input);
		free(input);
		input = get_next_line(0);
	}
	if (!is_sorted(stack.a))
		clear_program(&stack, "KO", EXIT_SUCCESS);
	else if (is_sorted(stack.a))
		clear_program(&stack, "OK", EXIT_SUCCESS);
}

void	execute_action(t_data *stack, char *input)
{
	if (!ft_strncmp(input, "sa\n", 3))
		push_swap(&stack->a, &stack->b, SA, true);
	else if (!ft_strncmp(input, "sb\n", 3))
		push_swap(&stack->a, &stack->b, SB, true);
	else if (!ft_strncmp(input, "pa\n", 3))
		push_swap(&stack->a, &stack->b, PA, true);
	else if (!ft_strncmp(input, "pb\n", 3))
		push_swap(&stack->a, &stack->b, PB, true);
	else if (!ft_strncmp(input, "ra\n", 3))
		push_swap(&stack->a, &stack->b, RA, true);
	else if (!ft_strncmp(input, "rb\n", 3))
		push_swap(&stack->a, &stack->b, RB, true);
	else if (!ft_strncmp(input, "rr\n", 3))
		push_swap(&stack->a, &stack->b, RR, true);
	else if (!ft_strncmp(input, "rra\n", 4))
		push_swap(&stack->a, &stack->b, RRA, true);
	else if (!ft_strncmp(input, "rrb\n", 4))
		push_swap(&stack->a, &stack->b, RRB, true);
	else if (!ft_strncmp(input, "rrr\n", 4))
		push_swap(&stack->a, &stack->b, RRR, true);
	else
	{
		free(input);
		clear_program(stack, "Error", EXIT_FAILURE);
	}
}
