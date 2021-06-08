/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:35:12 by liafigli          #+#    #+#             */
/*   Updated: 2021/06/08 13:37:29 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    algo_4(t_stack **stack1, t_stack **stack2)
{
    t_stack *a;
    t_stack *b;
    t_stack *c;
	t_stack *d;
    
    a = (*stack1);
    b = (*stack1)->next;
    c = (*stack1)->next->next;
    d = (*stack1)->next->next->next;
    if (a->num < b->num && a->num < c->num && a->num < d->num)
        push_on_stack(stack1, stack2);
    if (b->num < a->num && b->num < c->num && b->num < d->num)
    {
        swap_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (c->num < a->num && c->num < b->num && c->num < d->num)
    {
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (d->num < a->num && d->num < b->num && d->num < c->num)
    {
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    algo_3(stack1);
    push_on_stack(stack2, stack1);
}

void    algo_5(t_stack **stack1, t_stack **stack2)
{
    int b;
    int c;
	int d;
    int e;
    
    b = (*stack1)->next->num;
    c = (*stack1)->next->next->num;
    d = (*stack1)->next->next->next->num;
    e = (*stack1)->next->next->next->next->num;
    if ((*stack1)->num < b && (*stack1)->num < c && \
     (*stack1)->num < d && (*stack1)->num < e)
        push_on_stack(stack1, stack2);
    if (b < (*stack1)->num && b < c && b < d && b < e)
    {
        swap_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (c < (*stack1)->num && c < b && c < d && c < e)
    {
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (d < (*stack1)->num && d < b && d < c && d < e)
    {
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    if (e < (*stack1)->num && e < b && e < c && e < d)
    {
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    algo_4(stack1, stack2);
    push_on_stack(stack2, stack1);
}

void ft_find_seq(t_stack **stack1)
{
    t_stack *tmp;
    t_stack *mem;
    t_stack *tmem;
    int i;
    int j;

    i = 0;
    j = 0;
    tmem = NULL;
    mem = NULL;
    tmp = *stack1;
    while (tmp->next)
    {
        if (tmem == NULL)
            i = 0;
        while (tmp->next && tmp->num == tmp->next->num - 1)
        {
            if (i == 0)
                tmem = tmp;
            i++;
            if (tmp->next)
                tmp = tmp->next;
        }
        if (j <= i)
        {
            mem = tmem;
            j = i;
            tmem = NULL;
        }
        if (tmp->next)
            tmp = tmp->next;
    }
    //printf("start :%d, successivi %d", mem->num, j); //se le cifre so diverse il printf manda in seg
}

void ft_algo_gen(int params, t_stack **stack1,t_stack **stack2)
{
    int pivot;
    int i;

    i = 0;
    pivot = params;
    ft_find_seq(stack1);
    t_stack *stick;
    stick = *stack2;
    t_stack *stick1;
    stick1 = *stack1;
}
