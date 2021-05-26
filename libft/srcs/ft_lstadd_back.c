/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:05:39 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/26 16:52:58 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_stack *lst, t_stack *new)
{
	t_stack	*i;

	if (!new)
		return ;
	if (!lst)
	{
		lst = new;
		return ;
	}
	i = lst;
	while (i->next)
		i = i->next;
	i->next = new;
}
