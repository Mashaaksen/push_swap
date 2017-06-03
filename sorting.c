/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:32:26 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 20:32:27 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			lower(t_list *list, int median)
{
	while (list->next != NULL)
		list = list->next;
	return (list->digit < median ? 1 : 0);
}

void		sorting_lower(int flag, int rotate_list, t_list **a, t_char **list)
{
	int		size;

	size = list_size(*a);
	if (rotate_list > size - rotate_list)
	{
		size -= rotate_list;
		while (size-- > 0)
			rotate(a, list, flag);
	}
	else
		while (rotate_list-- > 0)
			revers_rotate(a, list, flag);
}

int			*arr_value_b(int len, t_list *b)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 4);
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = find_median_in_list(b, len);
	return (tab);
}

int			*arr_value_a(int len, t_list *a)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 5);
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = ((len > 3 && list_size(a) != len) ? 1 : 0);
	tab[4] = find_median_in_list(a, len);
	return (tab);
}
