/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:11:37 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/20 19:11:40 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_list *a)
{
	t_list	*b;

	b = NULL;
	play(&a, b);
}

int			main(int ac, char **av)
{
	t_list	*a;

	a = NULL;
	if (ac > 1)
	{
		a = create_a(ac - 1, av, 0);
		valid_arg(ac - 1, av, a, 0);
		push_swap(a);
	}
}
