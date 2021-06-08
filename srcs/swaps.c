/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:51:16 by liafigli          #+#    #+#             */
/*   Updated: 2021/06/08 18:05:47 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(int *a, int *b)
{
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
    printf("swap\n");
}

void print_list(t_stack *stack1, t_stack *stack2)
{
    ft_putstr(" --------------\n");
    ft_putstr(" |stack1 stack2|\n");
    ft_putstr(" --------------\n");
    while (stack1 || stack2)
    {
        if (stack1)
        {
            ft_putnbr_fd(stack1->num, 1);
            stack1 = stack1->next;
        }
        ft_putstr("         ");
        if (stack1 == NULL && stack2)
            ft_putstr("  ");
        if (stack2)
        {
            ft_putnbr_fd(stack2->num, 1);
            stack2 = stack2->next;
        }
        ft_putchar_fd('\n', 1);
    }
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

void algo_3(t_stack **stack1)
{
    t_stack *x;
    t_stack *y;
    t_stack *z;
	
    x = *stack1;
    y = (*stack1)->next;
    z = (*stack1)->next->next;
	if (x->num > y->num && x->num > z->num)
	{
		rotate_all(stack1);
		if (y->num > z->num)
			swap_all(stack1);
		return ;
	}
    if (y->num > x->num && y->num > z->num)
	{
		rev_rotate_all(stack1);
		if (x->num < z->num)
			swap_all(stack1);
	}
	else
		swap_all(stack1);
}

int ft_tree(int argc, t_stack **stack1, t_stack **stack2)
{
    int params = argc - 1;
    if (params == 1)
        exit(0);
    if (params == 2)
        if ((*stack1)->num > (*stack1)->next->num)
            swap_all(stack1);
    if (params == 3)
        if (!(check_ordine(stack1)))
            algo_3(stack1);
    if (params == 4)
        if (!(check_ordine(stack1)))
		    algo_4(stack1, stack2);
    if (params == 5)
        if (!(check_ordine(stack1)))
		    algo_5(stack1, stack2);
    if (params >= 6)
        ft_algo_gen(argc - 1, stack1, stack2);
    return (0);
}