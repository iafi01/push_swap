/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:01:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/07/05 15:52:40 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi_swap(const char *str)
{
	int			i;
	int			sign;
	long int	sum;

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
			sum *= 10;
		if (str[i] >= '0' && str[i] <= '9')
			sum += str[i++] - '0';
		else
			return (-1);
	}
	if (sum * sign < -2147483648 || sum * sign > 2147483647)
		return (-1);
	return (sum * sign);
}

int	*check_value(int nlen, char **argv, int *integers)
{
	int	i;
	int	j;
	int	n;
	int	len;

	len = 0;
	i = 1;
	while (i < nlen)
	{
		j = 0;
		len = i - 1;
		if (ft_atoi_swap(argv[i]) == -1 && ft_strcmp(argv[i], "-1") == 0)
			_error("Errore Min/Max/Float");
		n = ft_atoi_swap(argv[i]);
		while (len != 0 && i != 1)
		{
			if (n == integers[j++])
				_error("Errore Duplicati");
			len--;
		}
		integers[i - 1] = n;
		i++;
	}
	return (integers);
}

int	count_number(char **argv)
{
	int	i;
	int	ret;
	int	j;

	i = 1;
	ret = 0;
	j = 0;
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

char	**argv_unico(char **argv, int len, int argc)
{
	char	**s;
	char	**f;
	int		j;
	int		i;
	int		k;

	j = 1;
	i = 1;
	k = 0;
	f = calloc(len, sizeof(char *));
	*f = calloc(len, sizeof(char));
	f[0] = argv[0];
	while (i < argc)
	{
		s = ft_split(argv[i++], ' ');
		k = 0;
		while (s[k])
			f[j++] = s[k++];
	}
	return (f);
}

int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;
	int		*integers;
	int		len;

	len = count_number(argv);
	if (len == 1)
		return (0);
	integers = malloc(sizeof(int) * len);
	if (!integers)
		return (0);
	if (len != argc - 1)
		argv = argv_unico(argv, len, argc);
	check_value(len + 1, argv, integers);
	stack1 = copy_struct(integers, len + 1);
	stack2 = NULL;
	set_index(&stack1);
	ft_tree(len, &stack1, &stack2);
	my_free(len, stack1);
	free(integers);
}
