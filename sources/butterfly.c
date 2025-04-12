/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:16:17 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/12 11:07:27 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_butterfly(t_stack **a, t_stack **b)
{
	while (*b)
	{
		bring_to_top(b, find_max(*b), B);
		push_swap(a, b, PA);
	}
}

void	do_butterfly(t_stack **a, t_stack **b, int size)
{
	int	counter;

	counter = 1;
	while (*a)
	{
		if ((int)(*a)->index <= counter)
		{
			push_swap(a, b, PB);
			push_swap(a, b, RB);
			counter++;
		}
		else if ((int)(*a)->index <= counter + size)
		{
			push_swap(a, b, PB);
			counter++;
		}
		else
			push_swap(a, b, RA);
	}
}

int	get_butterfy_size(t_stacks *stack)
{
	if (stack->size <= 100)
		return (stack->size / 5);
	return (stack->size / 11);
}

void	butterfly_sort(t_stacks *stack)
{
	int	size;

	size = get_butterfy_size(stack);
	do_butterfly(&stack->a, &stack->b, size);
	sort_butterfly(&stack->a, &stack->b);
}
