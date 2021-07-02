/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:48:18 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/07/02 16:27:53 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_hundred(t_stack **StackA, t_stack **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 17;
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

void	sort_twofifty(t_stack **StackA, t_stack **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 30;
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

void	sort_fivehundred(t_stack **StackA, t_stack **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 44;
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

void	sort_plus(t_stack **StackA, t_stack **StackB)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + 45;
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
