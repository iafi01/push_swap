/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warnings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:01:53 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/05 15:04:37 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	_error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

void	init_algo_5(t_stack **stack1, int *k)
{
	k[0] = (*stack1)->num;
	k[1] = (*stack1)->next->num;
	k[2] = (*stack1)->next->next->num;
	k[3] = (*stack1)->next->next->next->num;
	k[4] = (*stack1)->next->next->next->next->num;
}

void	my_free(int len, int *integers)
{
	int i = 0;
	while (i < len)
	{
		if (integers)
			free(integers);
		i++;
	}	
}
