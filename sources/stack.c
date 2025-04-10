/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:12:13 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/10 22:08:08 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_stack(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_addback(t_stack **stack, t_stack *new)
{
	if (!*stack && new)
		*stack = new;
	else if (*stack && new)
		last_stack(*stack)->next = new;
}

t_stack	*new_stack(char *argv, long int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->argv = argv;
	new->value = value;
	new->next = NULL;
	return (new);
}
