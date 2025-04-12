/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:48:31 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/12 10:39:34 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

/**
 * Enum for stack actions used in push_swap operations.
 * - SA: Swap the top two elements of stack A.
 * - SB: Swap the top two elements of stack B.
 * - PA: Push the top element of stack B onto stack A.
 * - PB: Push the top element of stack A onto stack B.
 * - RA: Rotate stack A (top element moves to the bottom).
 * - RB: Rotate stack B (top element moves to the bottom).
 * - RR: Rotate both stacks A and B at the same time.
 * - RRA: Reverse rotate stack A (bottom element moves to the top).
 * - RRB: Reverse rotate stack B (bottom element moves to the top).
 * - RRR: Reverse rotate both stacks A and B at the same time.
 */
typedef enum e_action
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_action;

typedef enum e_stack_id
{
	A,
	B
}	t_stack_id;

/**
 * Represents a single node in a stack.
 * - argv: The original string input passed for this node.
 * - value: The integer value of the input, which is used in sorting.
 * - index: The index assigned after sorting.
 * - next: Pointer to the next node in the stack, forming a linked list.
 */
typedef struct s_stack
{
	char			*argv;
	unsigned int	index;
	long int		value;
	struct s_stack	*next;
}	t_stack;

/**
 * Represents the stacks and metadata for the sorting program.
 * - a: Pointer to stack A, which holds the primary list of elements.
 * - b: Pointer to stack B, which temporarily stores elements during sorting.
 * - size: The total number of elements initially present in stack A.
 */
typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	size;
}	t_stacks;

/**
 * Prints the contents of both stacks A and B.
 * - Prints stack A first and stack B second.
 * 
 * @param stack  Pointer to the stacks structure.
 */
void	print_stacks(t_stack *a, t_stack *b);

/**
 * Initializes the stack structure from command-line arguments.
 * - Parses and validates input.
 * - Adds valid numbers to stack A.
 * - Splits space-separated numbers if necessary.
 * - Sets the size of the stack and assigns sorted indexes.
 * 
 * @param stack  Pointer to the stacks structure.
 * @param argc   Argument count.
 * @param argv   Argument vector.
 */
void	init_stacks(t_stacks *stack, int argc, char *argv[]);

/**
 * Validates the stack:
 * - All values must be within INT_MIN and INT_MAX.
 * - No duplicate values allowed.
 * - Special case check for valid representations of 0 (e.g. "0", "+0").
 * 
 * @param a  Pointer to the top of stack A.
 * @return   true if valid, false otherwise.
 */
bool	parser(t_stack *a);

/**
 * Checks the stack for any duplicate values.
 * - Loops through the stack and checks if any value repeats.
 * 
 * @param a  Pointer to the top of the stack.
 * @return   true if duplicates are found, false otherwise.
 */
bool	has_duplicates(t_stack *a);

/**
 * Assigns a sorted index to each node in the stack.
 * - The smallest value gets index 1, the next smallest gets index 2, and so on.
 * 
 * @param a  Pointer to the top of the stack.
 */
void	assign_sorted_index(t_stack *a);

/**
 * Frees all dynamically allocated memory associated with the stack
 * and exits the program with the given exit code.
 * If the exit code is EXIT_FAILURE, prints an error message.
 * 
 * @param stack      Pointer to the stacks structure that holds the stacks A and B.
 * @param str        String to be printed in case of error.
 * @param exit_code  Exit code to terminate the program with.
 */
void	clear_program(t_stacks *stack, char *str, int exit_code);

/**
 * Creates a new stack node.
 * - Allocates memory for a new node and initializes its fields.
 * 
 * @param argv  The original argument string for this node.
 * @param value The long integer value to store in this node.
 * @return Pointer to the new stack node, or NULL on allocation failure.
 */
t_stack	*new_stack(char *argv, long int value);

/**
 * Returns the number of elements in the stack.
 * - Loops through the stack and counts the nodes.
 * 
 * @param stack Pointer to the top of the stack.
 * @return Number of nodes in the stack.
 */
int		stack_size(t_stack *stack);

/**
 * Returns the last node of a stack.
 * - Loops through the stack until the last node is reached.
 * 
 * @param stack Pointer to the top of the stack.
 * @return Pointer to the last node in the stack, or NULL if stack is empty.
 */
t_stack	*last_stack(t_stack *stack);

/**
 * Adds a new node to the end of the stack.
 * - If the stack is empty, the new node becomes the top.
 * - Otherwise, it is added at the end.
 * 
 * @param stack Pointer to the pointer of the stack.
 * @param new   The new node to be added.
 */
void	stack_addback(t_stack **stack, t_stack *new);

/**
 * Swaps the top two elements of stack A or B.
 * - If the action is SA, stack A is swapped.
 * - If the action is SB, stack B is swapped.
 * 
 * @param a       Pointer to stack A.
 * @param b       Pointer to stack B.
 * @param action  Action type (SA or SB).
 */
void	swap(t_stack **a, t_stack **b, t_action action);

/**
 * Pushes the top element from one stack to the other.
 * - If the action is PA, the top of stack B is pushed to stack A.
 * - If the action is PB, the top of stack A is pushed to stack B.
 * 
 * @param a       Pointer to stack A.
 * @param b       Pointer to stack B.
 * @param action  Action type (PA or PB).
 */
void	push(t_stack **a, t_stack **b, t_action action);

/**
 * Rotates the stack upwards (top element moves to the bottom).
 * - If the action is RA or RR, stack A is rotated.
 * - If the action is RB or RR, stack B is rotated.
 * 
 * @param a       Pointer to stack A.
 * @param b       Pointer to stack B.
 * @param action  Action type (RA, RB, or RR).
 */
void	rotate(t_stack **a, t_stack **b, t_action action);

/**
 * Reverse rotates the stack (bottom element becomes top).
 * - If the action is RRA or RRR, stack A is reverse rotated.
 * - If the action is RRB or RRR, stack B is reverse rotated.
 * 
 * @param a       Pointer to stack A.
 * @param b       Pointer to stack B.
 * @param action  Action type (RRA, RRB, or RRR).
 */
void	rev_rotate(t_stack **a, t_stack **b, t_action action);

/**
 * Executes the appropriate stack action and prints it.
 * - Determines the action (swap, push, rotate, reverse rotate) and performs it.
 * 
 * @param a       Pointer to stack A.
 * @param b       Pointer to stack B.
 * @param action  Action type to perform.
 */
void	push_swap(t_stack **a, t_stack **b, t_action action);

/**
 * Sorts the stack when the number of elements is small (3 or fewer).
 * - This is a basic sorting function that can quickly sort small stacks.
 * 
 * @param stack  Pointer to the stacks structure.
 */
void	tiny_sort(t_stacks *stack);

void	sort_three(t_stack **a, t_stack **b);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
void	bring_to_top(t_stack **stack, t_stack *target, t_stack_id id);
void	butterfly_sort(t_stacks *stack);
int ft_log2(int n);
void	bring_to_top(t_stack **stack, t_stack *target, t_stack_id id);
int	find_position(t_stack **stack, t_stack *target);

/**
 * Converts a string to a long integer.
 * - Handles string to integer conversion, including negative numbers.
 * 
 * @param ptr  The string to be converted to a long.
 * @return The long integer value.
 */
long	ft_atol(char *ptr);

/**
 * Duplicates a string by allocating new memory for it.
 * - The new string is identical to the original.
 * 
 * @param src  The string to duplicate.
 * @return A pointer to the new string.
 */
char	*ft_strdup(char *src);

/**
 * Splits a string into an array of substrings based on a separator character.
 * - Allocates a new array of strings, with each entry being a word from 's'.
 * 
 * @param s     The input string to split.
 * @param sep   The separator character.
 * @return      A null-terminated array of strings (words), or NULL on error.
 */
char	**ft_split(char *s, char sep);

/**
 * Frees a dynamically allocated 2d array of strings.
 * - Frees each row of the array, then the array itself.
 * 
 * @param matrix  The 2d array to free.
 */
void	free_matrix_2d(void **matrix);

/**
 * Checks if the stack is sorted.
 * - Returns true if the stack is sorted in ascending order, false otherwise.
 * 
 * @param a  Pointer to the top of stack A.
 * @return   true if sorted, false otherwise.
 */
bool	is_sorted(t_stack *a);

/**
 * Prints the action performed (swap, push, rotate, reverse rotate).
 * - Used for debugging or output in the program.
 * 
 * @param action  The action to print.
 */
void	put_action(t_action action);

#endif