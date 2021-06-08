/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:35:12 by liafigli          #+#    #+#             */
/*   Updated: 2021/06/08 17:43:59 by liafigli         ###   ########.fr       */
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

int *ft_find_seq(t_stack **stack1)
{
    t_stack *tmp;
    t_stack *mem;
    t_stack *tmem;
    int i;
    int j;
    int *seq;
    int x;

    x = 0;
    i = 0;
    j = 0;
    seq = malloc(sizeof(int)*600);
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
    while (mem && j-- + 1)
    {
        seq[x++] = mem->num;
        mem = mem->next;
    }
    return (seq);
}

int check_set_numbers(int num, int *list)
{
    int i;

    i = 0;
    while (list[i])
    {
        if (num == list[i++])
            return (0);
    }
    return (1);
}

void ft_algo_gen(int params, t_stack **stack1,t_stack **stack2)
{
    int pivot;
    int i;
    int *seq;
    t_stack *tmp;

    tmp = *stack1;
    i = 0;
    seq = malloc(sizeof(int)*600);
    pivot = params;
    seq = ft_find_seq(stack1);
    while (tmp->next && params--)
    {
        if (check_set_numbers(tmp->num, seq) == 1)
        {
            tmp = tmp->next;
            push_on_stack(stack1, stack2);
        }
        else
        {
            tmp = tmp->next;
            rotate_all(stack1);
        }
    }
}
