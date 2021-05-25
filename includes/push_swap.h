/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:44:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/25 17:39:31 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include <stdlib.h>

typedef struct  s_stack
{
    int	num;
	struct s_stack *next;
} t_stack;

//warnings
void _error(char *s);

//swaps
void swap(int *a, int *b);

//commands
int swap_all(t_stack *head);
int rotate_all(t_stack *head);

//push_swap
t_stack *create_new_node(void);
t_stack    *copy_struct(int *valori, int argc);
int    ft_atoi_swap(const char *str);
int *check_value(int argc, char **argv, int *integers);

#endif