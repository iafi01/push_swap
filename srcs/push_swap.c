/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:01:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/23 17:26:34 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/push_swap.h"
#include <stdio.h>

static int    ft_atoi(const char *str)
{
    int                    i;
    int                    sign;
    long int            sum;

    sum = 0;
    sign = 1;
    i = 0;
    if (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
            sign *= -1;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum *= 10;
            sum += str[i] - '0';
            i++;
        }
        else
            return (-1) ;
    }
    if (sum < -2147483648 || sum > 2147483647)
        return (-1);
    return (sum * sign);
}

int check_errors(int argc, char **argv, t_stack *lista)
{
	int    	i;
    int 	j;
    int 	n;
    int integers[argc-1];
    int len;
    
    len = 0;
    i = 1;
    while (i < argc)
    {
        j = 0;
        len = i;
        if (ft_atoi(argv[i]) == -1)
        {
            printf("Errore Min/Max/Float");
            return (-1);
        }
        n = ft_atoi(argv[i]);
        while (len != 0 && i != 1)
        {
            if (n == integers[j++])
            {
                printf("Errore Duplicates");
                return (-1);
            }
            len--;
        }
        integers[i++] = n;
    }
}

int main(int argc, char **argv)
{
    t_stack *stackA;
	t_stack *stackb;

	
}