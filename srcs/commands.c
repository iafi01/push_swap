/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:39:44 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/02 16:44:40 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//sa sb
int swap_all(t_stack **head, int i)
{
    t_stack *stack;

    stack = *head;
    if (stack && stack->next)
        swap(&stack->num, &stack->next->num);
	if (i == 1)
		write(1,"sa\n",3);
	if (i == 2)
		write(1,"sb\n",3);
    return (0);
}

void rotate_all(t_stack **head, int i)
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
	if (i == 1)
		write(1,"ra\n",3);
	if (i == 2)
		write(1,"rb\n",3);
}

void rev_rotate_all(t_stack **head, int i)
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
	if (i == 1)
		write(1,"rra\n",4);
	if (i == 2)
		write(1,"rrb\n",4);
}

void push_on_stack(t_stack **head, t_stack **head2, int i)
{
	t_stack *stack1;
	t_stack *stack2;
	t_stack *tmp;

	tmp = *head;
	if ((*head)->next)
		stack1 = (*head)->next;
	else
		stack1 = NULL;
	stack2 = *head2;

	tmp->next = NULL;
	if (stack2)
		tmp->next = stack2;
	stack2 = tmp;
	*head = stack1;
	*head2 = stack2;
	if (i == 1)
		write(1,"pa\n",3);
	if (i == 2)
		write(1,"pb\n",3);
}