/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:39:44 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/03 15:58:21 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_all_n(t_stack **head, int i, int n)
{
	while (n--)
		swap_all(head, i);
}

void	rotate_all_n(t_stack **head, int i, int n)
{
	while (n--)
		rotate_all(head, i);
}

void	rev_rotate_all_n(t_stack **head, int i, int n)
{
	while (n--)
		rev_rotate_all(head, i);
}

void	push_on_stack_n(t_stack **head, t_stack **head2, int i, int n)
{
	while (n--)
		push_on_stack(head, head2, i);
}
