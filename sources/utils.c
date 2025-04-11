/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:05:35 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/11 10:14:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *ptr)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while ((*ptr >= 9 && *ptr <= 13) || (*ptr == 32))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr)
	{
		if ((*ptr >= '0' && *ptr <= '9'))
			res = (res * 10) + (*ptr - '0');
		else
			return (0);
		ptr++;
	}
	return (sign * res);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dst;

	i = 0;
	while (src[i])
		i++;
	dst = malloc(i + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

void	free_matrix_2d(void **matrix)
{
	int	index;

	index = 0;
	if (!matrix)
		return ;
	while (matrix[index])
		free(matrix[index++]);
	free(matrix);
}

bool	has_duplicates(t_stack *a)
{
	t_stack	*current;
	t_stack	*checker;

	current = a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (true);
			checker = checker->next;
		}
		current = current->next;
	}
	return (false);
}

bool	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

void	put_action(t_action action)
{
	if (action == SA)
		write(1, "sa\n", 3);
	else if (action == SB)
		write(1, "sb\n", 3);
	else if (action == PA)
		write(1, "pa\n", 3);
	else if (action == PB)
		write(1, "pb\n", 3);
	else if (action == RA)
		write(1, "ra\n", 3);
	else if (action == RB)
		write(1, "rb\n", 3);
	else if (action == RR)
		write(1, "rr\n", 3);
	else if (action == RRA)
		write(1, "rra\n", 4);
	else if (action == RRB)
		write(1, "rrb\n", 4);
	else if (action == RRR)
		write(1, "rrr\n", 4);
}

void	print_stacks(t_stacks *stack)
{
	while (stack->a)
	{
		printf("%u: %ld\n", stack->a->index, stack->a->value);
		stack->a = stack->a->next;
	}
	if (!stack->a)
		printf("NULL\n");
	printf("------------------------------\n");
	while (stack->b)
	{
		printf("%u: %ld\n", stack->b->index, stack->b->value);
		stack->b = stack->b->next;
	}
	if (!stack->b)
		printf("NULL\n");
}
