/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:01:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/06/30 16:51:16 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *create_new_node(void)
{
    t_stack *first;

    first = (t_stack*)malloc(sizeof(t_stack));
    first->num = 0;
    first->next = NULL;
    return (first);
}

t_stack    *copy_struct(int *valori, int len)
{
    t_stack *stack1;
    t_stack *ret;
    int i;

    stack1 = create_new_node();
    ret = stack1;
    i = 1;
    while (i < len)
    {
        stack1->num = valori[i++];
        stack1->next = create_new_node();
        stack1 = stack1->next;
    }
    stack1 = ret;
    delete_last_node(&stack1);
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

int *check_value(int nlen, char **argv, int *integers)
{
	int    	i;
    int 	j;
    int 	n;
    int     len;
    
    len = 0;
    i = 1;
    while (i < nlen)
    {
        j = 0;
        len = i;
        if (ft_atoi_swap(argv[i]) == -1 && ft_strcmp(argv[i],"-1") == 0)
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

int count_number(char **argv)
{
    int i = 1;
    int ret = 0;
    int j = 0;
    
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] == ' ')
            {
                ret++;
            }
            j++;
        } 
        i++;
    }
    return (ret + i - 1);
}

char **argv_unico(char **argv_copy, int len)
{
    char **argv;
    int i;
    int j;
    int k;
    int m;

    argv = malloc(sizeof(char*) * len + 1);
    i = 0;
    j = 0;
    k = 0;
    m = 0;
    while (argv_copy[i++])
    {
        j = 0;
        while (argv_copy[j])
        {
            if (argv_copy[i][j] != ' ')
                argv[k][m] = argv_copy[i][j];
            else
            {
                k++;
                m = -1;
            }
            j++;
            m++;
        }
    }
    return (argv);
}

int main(int argc, char **argv)
{
    t_stack *stack1;
    t_stack *stack2;
    int *integers;
    int len;

    len = count_number(argv);
    if (len == 1)
        return (0);
    integers = malloc(sizeof(int) * len);
    if (len != argc - 1)
        /*argv = argv_unico(argv, len)*/; //ora sovrascrivo tutti gli argv come un array unico*/
    check_value(len + 1, argv, integers);
    stack1 = copy_struct(integers, len + 1);
    stack2 = NULL;
    calculate_index(len, &stack1);
    ft_tree(len, &stack1, &stack2);
    print_list(stack1,stack2);
}
