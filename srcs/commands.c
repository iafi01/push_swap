/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:39:44 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/25 18:09:38 by liafigli         ###   ########.fr       */
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

int rotate_all(t_stack *head)
{
    t_stack *tmp;

    tmp = head;/*
    while (tmp)
        tmp = tmp->next;
    tmp->next = create_new_node();
    tmp->next = head;
    head->next = NULL;*/
    return (0);
}