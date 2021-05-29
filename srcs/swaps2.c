/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:35:12 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/29 15:10:51 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    algo_4(t_stack **stack1, t_stack **stack2)
{
    int a;
    int b;
    int c;
	int d;
    
    a = (*stack1)->num;
    b = (*stack1)->next->num;
    c = (*stack1)->next->next->num;
    d = (*stack1)->next->next->next->num;
    if (a < b && a < c && a < d)
        push_on_stack(stack1, stack2);
    if (b < a && b < c && b < d)
    {
        swap_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (c < a && c < b && c < d)
    {
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (d < a && d < b && d < c)
    {
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    algo_3(stack1);
    push_on_stack(stack2, stack1);
}

void    algo_5(t_stack **stack1, t_stack **stack2)
{
    int a;
    int b;
    int c;
	int d;
    int e;
    
    a = (*stack1)->num;
    b = (*stack1)->next->num;
    c = (*stack1)->next->next->num;
    d = (*stack1)->next->next->next->num;
    e = (*stack1)->next->next->next->next->num;
    if (a < b && a < c && a < d && a < e)
        push_on_stack(stack1, stack2);
    if (b < a && b < c && b < d && b < e)
    {
        swap_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (c < a && c < b && c < d && c < e)
    {
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (d < a && d < b && d < c && d < e)
    {
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (e < a && e < b && e < c && e < d)
    {
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    algo_4(stack1, stack2);
    push_on_stack(stack2, stack1);
}