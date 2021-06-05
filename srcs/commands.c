/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:39:44 by liafigli          #+#    #+#             */
/*   Updated: 2021/06/05 15:33:36 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//sa sb
int swap_all(t_stack **head)
{
    t_stack *stack;

    stack = *head;
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

void rev_rotate_all(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;
	t_stack *penultimo;

	first = *head;
	if (!(first && first->next))
		return ;
	last = first;
	while (last->next)
	{
		penultimo = last;
		last = last->next;
	}
	last->next = first;
	penultimo->next = NULL;
	*head = last;
}

void push_on_stack(t_stack **head, t_stack **head2)
{
	t_stack *stack1;
	t_stack *stack2;
	t_stack *tmp;

	tmp = *head;
	stack1 = (*head)->next;
	stack2 = *head2;

	tmp->next = NULL;
	if (stack2)
		tmp->next = stack2;
	stack2 = tmp;
	*head = stack1;
	*head2 = stack2;
}