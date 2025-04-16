/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:48:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/16 14:20:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	stack;

	init_stacks(&stack, argc, argv);
	if (!is_sorted(stack.a))
	{
		if (stack.size <= 5)
			tiny_sort(&stack);
		else if (stack.size > 5)
			butterfly_sort(&stack);
	}
	clear_program(&stack, NULL, EXIT_SUCCESS);
}
