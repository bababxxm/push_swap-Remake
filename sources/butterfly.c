/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:16:17 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/11 12:02:28 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 0;
	if (size <= 100)
		chunk_size = size / 5;
	else if (size > 100)
		chunk_size = size / 11;
	else if (size > 1000)
		chunk_size = ft_log2(size) * 1.5;
	return (chunk_size);
}

void	split_chunk(t_stack **a, t_stack **b, int chunk_size)
{
	int	start;
	int	end;
	int	counter;
	
	while (stack_size(*a) > 3)
		push_swap(a, b, PB);
	sort_three(a, b);
	start = 1;
	end = chunk_size;
	while (*b)
	{
		if (top(*b)->index)
		start += chunk_size;
		end += chunk_size;
	}
}

void	chunk_sort(t_stacks *stack)
{
	int	chunk_size;

	chunk_size = get_chunk_size(stack->size);
	split_chunk(&stack->a, &stack->b, chunk_size);
}