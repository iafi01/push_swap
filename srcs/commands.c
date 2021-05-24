/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:39:44 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/24 15:04:53 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//sa sb
int swap_all(t_stack **head)
{
    t_stack *stack;

    stack = *head;
    if (stack && stack->next)
        swap(&stack->num, &stack->next->num);
    return (0);
}

