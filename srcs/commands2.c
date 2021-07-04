/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:39:44 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/04 13:08:08 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_all_n(t_stack **head, int n, int i)
{
	while (n--)
		swap_all(head, i);
}

void	rotate_all_n(t_stack **head, int n, int i)
{
	while (n--)
		rotate_all(head, i);
}

void	rev_rotate_all_n(t_stack **head, int n, int i)
{
	while (n--)
		rev_rotate_all(head, i);
}

void	push_on_stack_n(t_stack **head, t_stack **head2, int n, int i)
{
	while (n--)
		push_on_stack(head, head2, i);
}
