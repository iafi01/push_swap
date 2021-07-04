/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:44:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/04 13:21:06 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>

//warnings
void	_error(char *s);
void	init_algo_5(t_stack **stack1, int *k);

//utils
int		check_ordine(t_stack **stack);
void	calculate_index(int params, t_stack **stack);
int		find_index(t_stack **stack, int n);
int		find_num(t_stack **stack, int index);
void	set_index(t_stack **Stack);

//swaps
void	swap(int *a, int *b);
void	print_list(t_stack *stack1, t_stack *stack2);
void	delete_last_stack(t_stack **head);
void	algo_3(t_stack **stack1);
int		ft_tree(int argc, t_stack **stack1, t_stack **stack2);

//swaps2
int		*ft_find_seq(t_stack **stack1);
void	algo_4(t_stack **stack1, t_stack **stack2);
void	algo_5(t_stack **stack1, t_stack **stack2);
void	ft_algo_gen(int params, t_stack **stack1, t_stack **stack2);

//commands
int		swap_all(t_stack **head, int i);
void	rotate_all(t_stack **head, int i);
void	rev_rotate_all(t_stack **head, int i);
void	push_on_stack(t_stack **head, t_stack **head2, int i);

//commands2
void	swap_all_n(t_stack **head, int n, int i);
void	rotate_all_n(t_stack **head, int n, int i);
void	rev_rotate_all_n(t_stack **head, int n, int i);
void	push_on_stack_n(t_stack **head, t_stack **head2, int n, int i);

//push_swap
t_stack	*create_new_node(void);
t_stack	*copy_struct(int *valori, int len);
int		count_number(char **argv);
int		ft_atoi_swap(const char *str);
int		*check_value(int nlen, char **argv, int *integers);

//algos20+
int		stack_len(t_stack **Stack);
void	pushback_all(t_stack **StackA, t_stack **StackB);
void	ra_rra_pos(t_stack **a, int pos);
int		compare_smallest_pos(t_stack **Stack, int chunk);
int		smallest_pos(t_stack **Stack);
void	sort_twenty(t_stack **StackA, t_stack **StackB);
void	sort_fifty(t_stack **StackA, t_stack **StackB);
void	sort_hundred(t_stack **StackA, t_stack **StackB);
void	sort_twofifty(t_stack **StackA, t_stack **StackB);
void	sort_fivehundred(t_stack **StackA, t_stack **StackB);

#endif