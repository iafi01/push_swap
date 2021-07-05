/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:48:40 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/07/05 13:49:24 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_chunks(int numbers)
{
	if (numbers == 20)
		return (5);
	if (numbers == 50)
		return (13);
	if (numbers == 100)
		return (17);
	if (numbers == 250)
		return (30);
	if (numbers == 500)
		return (44);
	if (numbers > 500)
		return (45);
	return (-1);
}

void	algoritmo(t_stack **StackA, t_stack **StackB, int n)
{
	int		chunk;
	int		pos;
	int		i;

	chunk = 0;
	i = 1;
	while (*StackA)
	{
		chunk = chunk + n;
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
