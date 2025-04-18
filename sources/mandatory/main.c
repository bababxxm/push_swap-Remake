/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:48:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/19 03:24:49 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	stack;

	init_stack(&stack, argc, argv);
	if (!is_sorted(stack.a))
	{
		if (stack.size <= 5)
			tiny_sort(&stack);
		else if (stack.size > 5)
			butterfly_sort(&stack);
	}
	clear_program(&stack, NULL, EXIT_SUCCESS);
}
