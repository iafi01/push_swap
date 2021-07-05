/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:51:16 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/05 11:38:04 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_list(t_stack *stack1, t_stack *stack2)
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

void	delete_last_stack(t_stack **head)
{
	t_stack	*toDelLast;
	t_stack	*preNode;

	if (*head == NULL)
		return ;
	else
	{
		toDelLast = *head;
		preNode = *head;
		while (toDelLast->next != NULL)
		{
			preNode = toDelLast;
			toDelLast = toDelLast->next;
		}
		if (toDelLast == *head)
			*head = NULL;
		else
			preNode->next = NULL;
		free(toDelLast);
	}
}

void	algo_3(t_stack **stack1)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*z;

	x = *stack1;
	y = (*stack1)->next;
	z = (*stack1)->next->next;
	if (x->num > y->num && x->num > z->num)
	{
		rotate_all(stack1, 1);
		if (y->num > z->num)
			swap_all(stack1, 1);
		return ;
	}
	if (y->num > x->num && y->num > z->num)
	{
		rev_rotate_all(stack1, 1);
		if (x->num < z->num)
			swap_all(stack1, 1);
	}
	else if (!(check_ordine(stack1)))
		swap_all(stack1, 1);
}

int	ft_tree(int params, t_stack **stack1, t_stack **stack2)
{
	if (check_ordine(stack1))
		return (0);
	else if (params == 1)
		exit(0);
	else if (params == 2)
		swap_all(stack1, 1);
	else if (params == 3)
		algo_3(stack1);
	else if (params == 4)
		algo_4(stack1, stack2);
	else if (params == 5)
		algo_5(stack1, stack2);
	else if (params >= 6 && params <= 20)
		algoritmo(stack1, stack2, get_chunks(20));
	else if (params > 20 && params <= 50)
		algoritmo(stack1, stack2, get_chunks(50));
	else if (params > 50 && params <= 100)
		algoritmo(stack1, stack2, get_chunks(100));
	else if (params > 100 && params <= 250)
		algoritmo(stack1, stack2, get_chunks(250));
	else if (params > 250 && params <= 500)
		algoritmo(stack1, stack2, get_chunks(500));
	else if (params > 500)
		algoritmo(stack1, stack2, get_chunks(501));
	return (0);
}
