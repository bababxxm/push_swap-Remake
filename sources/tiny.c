/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:47:21 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/11 01:35:50 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_stack **b)
{
	if ((*a)->index == 3)
		push_swap(a, b, RA);
	if ((*a)->next->index == 3)
		push_swap(a, b, RRA);
	if ((*a)->value > (*a)->next->value)
		push_swap(a, b, SA);
}

void	tiny_sort(t_stacks *stack)
{
	if (stack->size == 2)
		push_swap(&stack->a, &stack->b, SA);
	else if (stack->size == 3)
		sort_three(&stack->a, &stack->b);
	// else if (stack->size == 4)
	// 	sort_four(&stack->a, &stack->b);
	// else if (stack->size == 5)
	// 	sort_five(&stack->a, &stack->b);
}
