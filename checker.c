/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:32:43 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 15:32:45 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		flag(char **av, t_flag **flags, int i)
{
	if (av[i] != NULL)
		if (!ft_strcmp(av[i], "-n") || !ft_strcmp(av[i], "-p1") ||
			!ft_strcmp(av[i], "-p2"))
		{
			(*flags)->flags++;
			if (!ft_strcmp(av[i], "-n"))
			{
				(*flags)->n = 1;
				flag(av, flags, 2);
			}
			else if (!ft_strcmp(av[i], "-p1"))
				(*flags)->p1 = 1;
			else if (!ft_strcmp(av[i], "-p2"))
				(*flags)->p2 = 1;
		}
}

int			main(int ac, char **av)
{
	t_list	*a;
	t_char	*arr;
	t_flag	*flags;

	arr = NULL;
	if (ac > 1)
	{
		flags = (t_flag *)malloc(sizeof(t_flag));
		flags->flags = 0;
		flags->n = 0;
		flags->p1 = 0;
		flags->p2 = 0;
		flag(av, &flags, 1);
		a = create_a(ac - 1, av, flags->flags);
		if ((flags->p1 == 1 || flags->p2 == 1) && a != NULL)
			print_stacks(a, NULL);
		valid_arg((flags->flags == 0 ? ac - 1 : ac - 1 - flags->flags), av, a,
			flags->flags);
		arr = create_stack(arr, a);
		check_stack_arr(&arr, &a, &flags);
	}
	return (0);
}
