/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:39:44 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/26 18:51:52 by liafigli         ###   ########.fr       */
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

void rotate_all(t_stack **head)
{
    t_stack	*first;
	t_stack	*last;
	t_stack	*stack;

	stack = *head;
	if (!(stack && stack->next))
		return ;
	first = stack;
	stack = stack->next;
	last = stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = stack;
}