/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:51:16 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/28 14:36:32 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(int *a, int *b)
{
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_list(t_stack *stack1, t_stack *stack2)
{
    ft_putstr(" --------------\n");
    ft_putstr("| stack1 stack2|\n");
    while (stack1 || stack2)
    {
        ft_putstr(" --------------\n");
        ft_putstr("|  ");
        if (stack1)
            ft_putstr("%d",stack1->num);
        ft_putstr("    |");
        if (stack2)
            ft_putstr("%d",stack2->num);
        ft_putstr("      |");
        ft_putstr("\n");
        stack1 = stack1->next;
    }
    ft_putstr(" --------------\n");
}

void delete_last_node(t_stack **head)
{
   t_stack *toDelLast, *preNode;
    if(*head == NULL)
        return ;
    else
    {
        toDelLast = *head;
        preNode = *head;
        while(toDelLast->next != NULL)
        {
            preNode = toDelLast;
            toDelLast = toDelLast->next;
        }
        if(toDelLast == *head)
            *head = NULL;
        else
            preNode->next = NULL;
        free(toDelLast);
    }
}