/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:01:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/25 14:44:24 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <string.h>

t_stack *create_new_node(void)
{
    t_stack *first;

    first = (t_stack*)malloc(sizeof(t_stack));
    first->num = 0;
    first->next = NULL;
    return (first);
}

t_stack    *copy_struct(int *valori)
{
    t_stack *stack1;
    int i;

    stack1 = create_new_node();
    i = 1;
    while (i < valori[0])
    {
        stack1->num = valori[i++];
        stack1->next = create_new_node();
    }
    return (stack1);
}

static int    ft_atoi_swap(const char *str)
{
    int						i;
    int						sign;
    long int				sum;

    sum = 0;
    sign = 1;
    i = 0;
    if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
			i++;
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

int *check_value(int argc, char **argv, int *integers)
{
	int    	i;
    int 	j;
    int 	n;
    int len;
    
    len = 0;
    i = 1;
    while (i < argc)
    {
        j = 0;
        len = i;
        if (ft_atoi_swap(argv[i]) == -1 && strcmp(argv[i],"-1") != 0)
            _error("Errore Min/Max/Float");
        n = ft_atoi_swap(argv[i]);
        while (len != 0 && i != 1)
        {
            if (n == integers[j++])
                _error("Errore Duplicati");
            len--;
        }
        integers[i++] = n;
    }
    return (integers);
}

int main(int argc, char **argv)
{
    t_stack *stack1;
    t_stack *stack2;
    int *valori;
    int integers[argc - 1];
    
    valori = check_value(argc, argv, integers);
    stack1 = copy_struct(valori);
    stack2 = NULL;
}


//valori[0] = argc-1 come istanziato su

//gcc srcs/push_swap.c srcs/warnings.c libft/srcs/*.c

