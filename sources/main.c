/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:48:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/10 22:05:10 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_program(t_stack *a, char **matrix, int exit_code)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp->argv);
		free(tmp);
	}
	if (matrix)
		free_matrix_2D((void **)matrix);
	if (exit_code == EXIT_FAILURE)
		write(2, "Error\n", 6);
	exit(exit_code);
}

bool	parser(t_stack *a)
{
	while (a)
	{
		if (a->value == 0)
		{
			if (a->argv[0] == '0' && a->argv[1] == '\0')
				return (true);
			if (a->argv[0] == '+' && a->argv[1] == '0' \
				&& a->argv[2] == '\0')
				return (true);
			else
				return (false);
		}
		// else if (has_duplicates(a, a->value))
		// 	return (false);
		else if (a->value < INT_MIN || a->value > INT_MAX)
			return (false);
		a = a->next;
	}
	return (true);
}

void	init_stack(t_stack **a, t_stack **b, int argc, char *argv[])
{
	int		i;
	int		j;
	char	**tmp;

	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 0;
	*a = NULL;
	*b = NULL;
	while (argv[++i])
	{
		if (!*argv[i])
			clear_program(*a, NULL, EXIT_FAILURE);
		j = -1;
		tmp = ft_split(argv[i], ' ');
		while (tmp[++j])
			stack_addback(a, new_stack( \
				ft_strdup(tmp[j]), ft_atol(tmp[j])));
		free_matrix_2D((void **)tmp);
	}
	if (!parser(*a))
		clear_program(*a, NULL, EXIT_FAILURE);
}


int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	init_stack(&a, &b, argc, argv);
	push_swap(&a, &b, RRR);
	print_stacks(a, b);
	clear_program(a, NULL, EXIT_SUCCESS);
}