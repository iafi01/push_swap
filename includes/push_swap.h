/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:44:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/06/28 15:11:09 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

//warnings
void _error(char *s);
int check_ordine(t_stack **stack);
void calculate_index(int params, t_stack **stack);
int find_index(t_stack **stack, int n);
int find_num(t_stack **stack, int index);

//swaps
void swap(int *a, int *b);
void print_list(t_stack *stack1, t_stack *stack2);
void delete_last_node(t_stack **head);
void algo_3(t_stack **stack1);
int ft_tree(int argc, t_stack **stack1, t_stack **stack2);

//swaps2
int     *ft_find_seq(t_stack **stack1);
void    algo_4(t_stack **stack1, t_stack **stack2);
void    algo_5(t_stack **stack1, t_stack **stack2);
void    ft_algo_gen(int params, t_stack **stack1,t_stack **stack2);

//commands
int swap_all(t_stack **head);
void rotate_all(t_stack **head);
void rev_rotate_all(t_stack **head);
void push_on_stack(t_stack **head, t_stack **head2);

//push_swap
t_stack *create_new_node(void);
t_stack    *copy_struct(int *valori, int len);
int    ft_atoi_swap(const char *str);
int *check_value(int nlen, char **argv, int *integers);


#endif