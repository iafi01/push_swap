/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:39:44 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/26 16:23:45 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//sa sb
int swap_all(t_stack *head)
{
    t_stack *stack;

    stack = head;
    if (stack && stack->next)
        swap(&stack->num, &stack->next->num);
    return (0);
}

t_stack *rotate_all(t_stack *head)
{
    while (head)
    {
        head = head->next;
    }
        
    return (head);
}