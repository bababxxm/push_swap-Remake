/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:05:35 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/10 22:08:18 by sklaokli         ###   ########.fr       */
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

void	free_matrix_2D(void **matrix)
{
	int	index;

	index = 0;
	if (!matrix)
		return ;
	while (matrix[index])
		free(matrix[index++]);
	free(matrix);
}

bool	has_duplicates(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	while (a)
	{
		printf("%ld\n", a->value);
		a = a->next;
	}
	printf("------------------------------\n");
	while (b)
	{
		printf("%ld\n", b->value);
		b = b->next;
	}
}
