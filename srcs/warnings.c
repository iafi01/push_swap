/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warnings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:01:53 by liafigli          #+#    #+#             */
/*   Updated: 2021/06/09 14:16:08 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void _error(char *s)
{
    write(1, s, ft_strlen(s));
    exit(0);
}

int check_ordine(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp->next)
    {
        if (tmp->num > tmp->next->num)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void calculate_index(int params, t_stack **stack)
{
    int index;
    t_stack *first;
    t_stack *second;

    first = *stack;
    second = (*stack)->next;
    while (first)
    {
        index = params;
        while (second->next)
        {
            if (first->num < second->num)
                index--;
            second = second->next;
        }
        if (first->num == second->num)
        {
            first->index = params;
            return;
        } 
        if (first->num < second->num)
            index--;
        first->index = index;
        first = first->next;
        if (first->next)
            second = first->next;
    }
}