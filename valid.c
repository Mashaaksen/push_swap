/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:34:07 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 15:34:08 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_arr(t_list *list)
{
	t_list		*tmp;
	int			nb;
	int			flag;

	nb = 0;
	flag = 0;
	while (list != NULL)
	{
		nb = list->digit;
		tmp = list;
		while (tmp != NULL)
		{
			nb == tmp->digit ? flag++ : 0;
			tmp = tmp->next;
		}
		if (flag > 1)
			return (1);
		flag = 0;
		list = list->next;
	}
	return (0);
}

int				max_min(char *str)
{
	long long	nb;
	int			error;

	error = 0;
	nb = ft_atoi_long(str);
	(nb > 2147483647 || nb < -2147483648) ? error++ : 0;
	return (error != 0 ? 1 : 0);
}

int				is_digit(char ch)
{
	if (ch < 48 || ch > 57)
		return (1);
	return (0);
}

int				is_plus(char ch)
{
	if (ch == 45 || ch == 43)
		return (1);
	return (0);
}

void			valid_arg(int len, char **av, t_list *list, int nb)
{
	int			min;
	int			i;
	int			flag;

	flag = 0;
	i = (nb == 0 ? 0 : nb);
	min = 0;
	while (++i <= len)
	{
		max_min(av[i]) == 1 ? message() : 0;
		while (*av[i] != '\0')
		{
			is_digit(*av[i]) == 1 ? flag++ : 0;
			is_plus(*av[i]) == 1 ? min++ : 0;
			av[i]++;
			if (min != 0 && (*av[i] <= 57 && *av[i] >= 48) && *av[i] != '\0')
			{
				min = 0;
				flag = 0;
			}
		}
	}
	if (flag != 0 || check_arr(list) == 1)
		message();
}
