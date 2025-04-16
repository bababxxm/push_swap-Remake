/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:05:15 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/16 21:03:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char		*input;
	t_stacks	stack;

	init_stacks(&stack, argc, argv);
	input = get_next_line(0);
	while (input)
	{
		read_action(&stack.action, input);
		free(input);
		input = get_next_line(0);
	}
	execute_actions(&stack, stack.action);
	if (!is_sorted(stack.a))
		clear_program(&stack, "KO", EXIT_SUCCESS);
	else if (is_sorted(stack.a))
		clear_program(&stack, "OK", EXIT_SUCCESS);
}

void	read_action(t_list **action, char *input)
{
	if (!ft_strncmp(input, "sa\n", 3))
		node_addback((void **)action, new_list(SA));
	else if (!ft_strncmp(input, "sb\n", 3))
		node_addback((void **)action, new_list(SB));
	else if (!ft_strncmp(input, "pa\n", 3))
		node_addback((void **)action, new_list(PA));
	else if (!ft_strncmp(input, "pb\n", 3))
		node_addback((void **)action, new_list(PB));
	else if (!ft_strncmp(input, "ra\n", 3))
		node_addback((void **)action, new_list(RA));
	else if (!ft_strncmp(input, "rb\n", 3))
		node_addback((void **)action, new_list(RB));
	else if (!ft_strncmp(input, "rr\n", 3))
		node_addback((void **)action, new_list(RR));
	else if (!ft_strncmp(input, "rra\n", 4))
		node_addback((void **)action, new_list(RRA));
	else if (!ft_strncmp(input, "rrb\n", 4))
		node_addback((void **)action, new_list(RRB));
	else if (!ft_strncmp(input, "rrr\n", 4))
		node_addback((void **)action, new_list(RRR));
}

void	merge_actions(t_list *current, t_list *next)
{
	if (next)
	{
		if ((current->value == RA && next->value == RB) \
			|| (current->value == RB && next->value == RA))
		{
			current->value = RR;
			current->next = next->next;
			free(next);
		}
		else if ((current->value == RRA && next->value == RRB) \
			|| (current->value == RRB && next->value == RRA))
		{
			current->value = RRR;
			current->next = next->next;
			free(next);
		}
	}
}

void	execute_actions(t_stacks *stack, t_list *action)
{
	while (action)
	{
		merge_actions(action, action->next);
		push_swap(&stack->a, &stack->b, action->value, true);
		action = action->next;
	}
}
