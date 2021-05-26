/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:44:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/26 18:50:46 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

//warnings
void _error(char *s);

//swaps
void swap(int *a, int *b);
void print_list(t_stack *stack1);

//commands
int swap_all(t_stack *head);
void rotate_all(t_stack **head);

//push_swap
t_stack *create_new_node(void);
t_stack    *copy_struct(int *valori, int argc);
int    ft_atoi_swap(const char *str);
int *check_value(int argc, char **argv, int *integers);

#endif