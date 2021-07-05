/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:01:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/05 14:54:56 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	if (!first)
		return (NULL);
	first->num = 0;
	first->next = NULL;
	return (first);
}

t_stack	*copy_struct(int *valori, int len)
{
	t_stack	*stack1;
	t_stack	*ret;
	int		i;

	stack1 = create_new_node();
	ret = stack1;
	i = 0;
	while (i < len - 1)
	{
		stack1->num = valori[i++];
		stack1->next = create_new_node();
		stack1 = stack1->next;
	}
	stack1 = ret;
	delete_last_stack(&stack1);
	return (ret);
}
