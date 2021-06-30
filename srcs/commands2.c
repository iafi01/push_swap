/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:39:44 by liafigli          #+#    #+#             */
/*   Updated: 2021/06/30 18:20:00 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int swap_all_n(t_stack **head, int i)
{
    while (i--)
        swap_all(head);
}

void rotate_all_n(t_stack **head, int i)
{
    while (i--)
        rotate_all(head);
}

void rev_rotate_all_n(t_stack **head, int i)
{
    while (i--)
        rev_rotate_all(head);
}

void push_on_stack_n(t_stack **head, t_stack **head2, int i)
{
    while (i--)
        push_on_stack(head, head2);
}

