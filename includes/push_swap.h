/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:44:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/23 14:11:50 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include <stdlib.h>

typedef struct  s_stack
{
    int	num;
	int diff;
	struct s_stack *next;
} t_stack;

void finish(char *s);

#endif