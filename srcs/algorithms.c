/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:48:40 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/07/02 16:49:01 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack **StackA)
{
	t_stack	*tmp;

	tmp = *StackA;
	if (tmp->num > tmp->next->num)
		swap_all(StackA, 1);
}

void	sort_three(t_stack **StackA)
{
	int		one;
	int		two;
	int		three;
	t_stack	*tmp;

	tmp = *StackA;
	one = tmp->num;
	two = tmp->next->num;
	three = tmp->next->next->num;
	if (one > two && two < three && three > one)
		swap_all(StackA, 1);
	else if (one > two && two > three && three < one)
	{
		swap_all(StackA, 1);
		rev_rotate_all(StackA, 1);
	}
	else if (one > two && two < three && three < one)
		rotate_all(StackA, 1);
	else if (one < two && two > three && three > one)
	{
		swap_all(StackA, 1);
		rotate_all(StackA, 1);
	}
	else if (one < two && two > three && three < one)
		rev_rotate_all(StackA, 1);
}

void	sort_five(t_stack **StackA, t_stack **StackB)
{
	int	size;
	int	pos;
	int	i;

	i = 0;
	size = stack_len(StackA);
	while (i < (size - 3))
	{
		pos = smallest_pos(StackA);
		ra_rra_pos(StackA, pos);
		push_on_stack(StackA, StackB, 2);
		i++;
	}
	sort_three(StackA);
	while (i > 0)
	{
		push_on_stack(StackA, StackB, 1);
		i--;
	}
}

void	sort_twenty(t_stack **StackA, t_stack **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 5;
		while (i <= chunk)
		{
			if (!(*StackA))
				break ;
			pos = compare_smallest_pos(StackA, chunk);
			ra_rra_pos(StackA, pos);
			push_on_stack(StackA, StackB, 2);
			i++;
		}
		set_index(StackB);
	}
	pushback_all(StackA, StackB);
}

void	sort_fifty(t_stack **StackA, t_stack **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 13;
		while (i <= chunk)
		{
			if (!(*StackA))
				break ;
			pos = compare_smallest_pos(StackA, chunk);
			ra_rra_pos(StackA, pos);
			push_on_stack(StackA, StackB, 2);
			i++;
		}
		set_index(StackB);
	}
	pushback_all(StackA, StackB);
}
