/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:01:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/05/25 18:10:11 by liafigli         ###   ########.fr       */
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

t_stack    *copy_struct(int *valori, int argc)
{
    t_stack *stack1;
    t_stack *ret;
    int i;

    stack1 = create_new_node();
    ret = stack1;
    i = 1;
    while (i < argc)
    {
        stack1->num = valori[i++];
        stack1->next = create_new_node();
        stack1 = stack1->next;
    }
    return (ret);
}

int    ft_atoi_swap(const char *str)
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
    int integers[argc - 1];
    
    check_value(argc, argv, integers);
    stack1 = copy_struct(integers, argc);
    stack2 = NULL;

    t_stack *tmp;
    swap_all(stack1);
    tmp = stack1;
    while (tmp)
    {
        printf("%d\n",tmp->num);
        tmp = tmp->next;
    }
}

/*  t_stack *tmp;
    tmp = stack1;
    while (tmp)
    {
        printf("%d\n",tmp->num);
        tmp = tmp->next;
    }
*/