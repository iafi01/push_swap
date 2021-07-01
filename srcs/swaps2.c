/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:35:12 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/01 15:57:28 by liafigli         ###   ########.fr       */
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
    else if (b->num < a->num && b->num < c->num && b->num < d->num)
    {
        swap_all(stack1);
        push_on_stack(stack1, stack2);
    }
    else if (c->num < a->num && c->num < b->num && c->num < d->num)
    {
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    else if (d->num < a->num && d->num < b->num && d->num < c->num)
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
    else if (b < (*stack1)->num && b < c && b < d && b < e)
    {
        swap_all(stack1);
        push_on_stack(stack1, stack2);
    }
    else if (c < (*stack1)->num && c < b && c < d && c < e)
    {
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    else if (d < (*stack1)->num && d < b && d < c && d < e)
    {
        rev_rotate_all(stack1);
        rev_rotate_all(stack1);
        push_on_stack(stack1, stack2);
    }
    else if (e < (*stack1)->num && e < b && e < c && e < d)
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
        while (tmp->next && tmp->index == tmp->next->index - 1)
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
     // lui mette lo zero dentro e lo vede come final
    return (seq);
}

int check_set_numbers(int num, int *list)
{
    int i;

    i = 0;
    while (list[i])
    {
        if ((int)num == (int)list[i++])
            return (0);
    }
    return (1);
}

int ft_intlen(int *n)
{
    int i;

    i = 0;
    while (n[i])
    {
        if (n[i] >= 0 && n[i] <= 9)
            return (i);
        i++;
    }
    return (0);
}

int check_pos_index(t_stack **stack, int index)
{
    t_stack **tmp;
    int i;

    i = 1;
    tmp = stack;
    while ((*tmp)->next)
    {
        if ((*tmp)->index == index)
            return (i);
        i++;
        tmp = &(*tmp)->next;
    }
    return (i);
}

int manage_rotation(int p1,int p2,int p3,int p4, int len)
{ //stare attento ai -1
    printf("i %d i+1 %d len-1 %d len %d ",p1,p2,p3,p4);
    if (p1 > p2 || p1 == -1)
        p1 = p2;
    if (p3 < p4 || p4 == -1)
        p4 = p3;
    if (len - p4 + 1 < p1 - 1)
        return ((len - p4 + 1) * -1);
    return (p1-1);
}

void ft_algo_gen(int params, t_stack **stack1,t_stack **stack2)
{
    int pivot;
    int i;
    int len;
    int *seq;
    int *conveniente;
    t_stack *tmp;
    t_stack *tmp2;
    int p1;
    int p2;
    int p3;
    int p4;
    int manage;
    
    i = 1;
    tmp = *stack1;
    len = params;
    seq = malloc(sizeof(int)*600);
    conveniente = malloc(sizeof(int)*600);
    pivot = params;
    seq = ft_find_seq(stack1);
    while (*seq)
        printf("%d", *seq++);
    while (check_ordine(stack1) == 0)
    {
        while (check_ordine(stack1) == 0)
        {
            p1 = -1;
            p2 = -1;
            p3 = -1;
            p4 = -1;
            manage = 0;
            if (check_set_numbers(find_num(stack1, i), seq) == 1)
                p1 = check_pos_index(stack1, i);
            if (check_set_numbers(find_num(stack1, i+1), seq) == 1)
                p2 = check_pos_index(stack1, i+1);
            if (check_set_numbers(find_num(stack1, len-1), seq) == 1)
                p3 = check_pos_index(stack1, len-1);
            if (check_set_numbers(find_num(stack1, len), seq) == 1)
                p4 = check_pos_index(stack1, len);
            if (!(p1 == -1 && p2 == -1 && p3 == -1 && p4 == -1))
                manage = manage_rotation(p1,p2,p3,p4,len);
            else
            {
                len--;
                i++;
            }
            if(manage > 0)
            {
                rotate_all_n(stack1, manage);
            } 
            else if (manage < 0)
            {
                rev_rotate_all_n(stack1, manage*-1);
            }
            push_on_stack(stack1, stack2);
        }
        tmp = *stack1;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp2 = *stack2;
    while (tmp2)
    {
        //printf(" %d %d",tmp2->num,tmp->num);
        if (tmp2->num > tmp->num)
        {
            push_on_stack(stack2, stack1);
            rotate_all(stack1);
        }
        else
            push_on_stack(stack2, stack1);
        if ((*stack1)->index == (*stack1)->next->index + 1)
            swap_all(stack1);
        tmp2 = *stack2;
    }
}
