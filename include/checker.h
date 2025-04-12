/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:08:08 by sklaokli          #+#    #+#             */
/*   Updated: 2025/04/12 14:54:52 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	execute_action(t_stacks *stack, char *action);

#endif