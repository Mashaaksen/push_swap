/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:33:26 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 15:33:27 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			message(void)
{
	ft_putstr(RED);
	ft_putstr("Error\n");
	ft_putstr(END);
	exit(0);
}

void			ok(void)
{
	ft_putstr(GRN);
	ft_putstr("OK\n");
	ft_putstr(END);
}

void			ko(void)
{
	ft_putstr(RED);
	ft_putstr("KO\n");
	ft_putstr(END);
}

void			exit_b(t_list *b)
{
	if (b != NULL)
	{
		ko();
		exit(0);
	}
}

long long		ft_atoi_long(char *str)
{
	long long	n;
	long long	res;

	res = 0;
	n = 1;
	if (!(*str))
		return (0);
	while (*(char *)str == ' ' || *(char *)str == '\f' || *(char *)str == '\r'
		|| *(char *)str == '\v' || *(char *)str == '\n'
		|| *(char *)str == '\t')
		str++;
	if (*(char *)str == '-' || *(char *)str == '+')
	{
		n = (*(char *)str == '-' ? -1 : 1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + *(char *)str - '0';
		str++;
	}
	return (res * n);
}
