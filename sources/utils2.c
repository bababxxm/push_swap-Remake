/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:28:27 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/12 10:30:04 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack *min;
	t_stack *current;

	min = stack;
	current = stack;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack *max;
	t_stack *current;

	max = stack;
	current = stack;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

int	find_position(t_stack **stack, t_stack *target)
{
	int		pos;
	t_stack	*tmp;

	pos = 1;
	tmp = *stack;
	while (tmp && tmp != target)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	bring_to_top(t_stack **stack, t_stack *target, t_stack_id id)
{
	if (find_position(stack, target) > stack_size(*stack) / 2)
	{
		while (*stack && (*stack) != target)
		{
			if (id == A)
				push_swap(stack, NULL, RRA);
			else if (id == B)
				push_swap(NULL, stack, RRB);
		}
	}
	else
	{
		while (*stack && (*stack) != target)
		{
			if (id == A)
				push_swap(stack, NULL, RA);
			else if (id == B)
				push_swap(NULL, stack, RB);
		}
	}
}


int ft_log2(int n)
{
    int log;

	log = 0;
    while (n >>= 1)
        log++;
    return (log);
}
