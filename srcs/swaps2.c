/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:35:12 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/04 13:23:03 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_4(t_stack **stack1, t_stack **stack2)
{
	int	k[4];

	k[0] = (*stack1)->num;
	k[1] = (*stack1)->next->num;
	k[2] = (*stack1)->next->next->num;
	k[3] = (*stack1)->next->next->next->num;
	if (k[0] < k[1] && k[0] < k[2] && k[0] < k[3])
		push_on_stack(stack1, stack2, 2);
	else if (k[1] < k[0] && k[1] < k[2] && k[1] < k[3])
	{
		swap_all(stack1, 1);
		push_on_stack(stack1, stack2, 2);
	}
	else if (k[2] < k[0] && k[2] < k[1] && k[2] < k[3])
	{
		rev_rotate_all_n(stack1, 2, 1);
		push_on_stack(stack1, stack2, 2);
	}
	else if (k[3] < k[0] && k[3] < k[1] && k[3] < k[2])
	{
		rev_rotate_all(stack1, 1);
		push_on_stack(stack1, stack2, 2);
	}
	algo_3(stack1);
	push_on_stack(stack2, stack1, 1);
}

void	algo_5(t_stack **stack1, t_stack **stack2)
{
	int	k[5];

	init_algo_5(stack1, k);
	if (k[0] < k[1] && k[0] < k[2] && k[0] < k[3] && k[0] < k[4])
		push_on_stack(stack1, stack2, 2);
	else if (k[1] < k[0] && k[1] < k[2] && k[1] < k[3] && k[1] < k[4])
		swap_all(stack1, 1);
	if (k[1] < k[0] && k[1] < k[2] && k[1] < k[3] && k[1] < k[4])
		push_on_stack(stack1, stack2, 2);
	else if (k[2] < k[0] && k[2] < k[1] && k[2] < k[3] && k[2] < k[4])
		rev_rotate_all_n(stack1, 3, 1);
	if (k[2] < k[0] && k[2] < k[1] && k[2] < k[3] && k[2] < k[4])
		push_on_stack(stack1, stack2, 2);
	else if (k[3] < k[0] && k[3] < k[1] && k[3] < k[2] && k[3] < k[4])
	{
		rev_rotate_all_n(stack1, 2, 1);
		push_on_stack(stack1, stack2, 2);
	}
	else if (k[4] < k[0] && k[4] < k[1] && k[4] < k[2] && k[4] < k[3])
	{
		rev_rotate_all(stack1, 1);
		push_on_stack(stack1, stack2, 2);
	}
	algo_4(stack1, stack2);
	push_on_stack(stack2, stack1, 1);
}

/*int	*ft_find_seq(t_stack **stack1)
{
	t_stack	*tmp;
	t_stack	*mem;
	t_stack	*tmem;
	int		i;
	int		j;
	int		*seq;
	int		x;

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
	return (seq);
}*/

int	check_set_numbers(int num, int *list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if ((int)num == (int)list[i++])
			return (0);
	}
	return (1);
}

int	ft_intlen(int *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (n[i] >= 0 && n[i] <= 9)
			return (i);
		i++;
	}
	return (0);
}

int	check_pos_index(t_stack **stack, int index)
{
	t_stack	**tmp;
	int		i;

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
