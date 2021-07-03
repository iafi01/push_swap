/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:47:12 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/07/02 16:49:12 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	smallest_pos(t_stack **Stack)
{
	int		pos;
	int		smallest;
	int		i;
	t_stack	*tmp;

	i = 0;
	pos = 0;
	tmp = *Stack;
	smallest = tmp->index;
	while (tmp)
	{
		if (smallest > tmp->index)
		{
			smallest = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	biggest_pos(t_stack **Stack)
{
	int		pos;
	int		biggest;
	int		i;
	t_stack	*tmp;

	i = 0;
	pos = 0;
	tmp = *Stack;
	biggest = (*Stack)->index;
	while (tmp)
	{
		if (biggest < tmp->index)
		{
			biggest = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	ra_rra_pos(t_stack **a, int pos)
{
	int	size;

	size = stack_len(a);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos != 0)
		{
			rev_rotate_all(a, 1);
			pos--;
		}
	}
	else if (pos <= size / 2)
	{
		while (pos != 0)
		{
			rotate_all(a, 1);
			pos--;
		}
	}
}

void	rb_rrb_pos(t_stack **b, int pos)
{
	int	size;

	size = stack_len(b);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos != 0)
		{
			rev_rotate_all(b, 2);
			pos--;
		}
	}
	else if (pos <= size / 2)
	{
		while (pos != 0)
		{
			rotate_all(b, 2);
			pos--;
		}
	}
}

void	pushback_all(t_stack **StackA, t_stack **StackB)
{
	int	pos;
	int	i;

	i = stack_len(StackB);
	pos = 0;
	while (*StackB && i)
	{
		pos = biggest_pos(StackB);
		rb_rrb_pos(StackB, pos);
		push_on_stack(StackB, StackA, 1);
		i--;
	}
}
