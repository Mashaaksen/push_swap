/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:35:55 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/08 17:36:00 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_digit(t_list *a, t_list *b)
{
	while (a != NULL && b != NULL)
	{
		ft_putnbr(a->digit);
		ft_putstr("             ");
		ft_putnbr(b->digit);
		ft_putstr("\n");
		b = b->next;
		a = a->next;
	}
	while (a != NULL)
	{
		ft_putnbr(a->digit);
		ft_putstr("             \n");
		a = a->next;
	}
	while (b != NULL)
	{
		ft_putstr("            ");
		ft_putnbr(b->digit);
		ft_putstr("\n");
		b = b->next;
	}
}

void	print_stacks(t_list *a, t_list *b)
{
	int	i;

	i = 6;
	ft_putstr(CYN);
	ft_putstr("___________START___________\n");
	ft_putstr("_____a_____     _____b_____\n");
	print_digit(a, b);
	ft_putstr("___________________________\n");
	ft_putstr("____________END____________");
	while (i-- > 0)
		ft_putstr("\n");
	ft_putstr(END);
}
