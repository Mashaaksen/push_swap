/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:24:00 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 20:24:01 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			choose_rule_3(t_list **a, t_list **b, t_char **list, int median)
{
	if ((*b)->digit <= median)
	{
		rotate(b, list, -1);
		return (1);
	}
	else if ((*b)->digit > median)
	{
		push(a, b, list, -1);
		return (-1);
	}
	return (0);
}

void		quicksort_2(t_list **a, t_list **b, int len, t_char **list)
{
	int		*tab;

	tab = arr_value_b(len, *b);
	if (len > 3)
		while (len > 0)
		{
			if (sort_median(*b, tab[3], len, -1) == 1)
				choose_rule_3(a, b, list, tab[3]) == 1 ? tab[1]++ : tab[0]++;
			else
				tab[2]++;
			len--;
		}
	else
		while (len-- > 0)
		{
			push(a, b, list, -1);
			tab[0]++;
		}
	quicksort(a, b, tab[0], list);
	tab[1] > 0 ? sorting_lower(-1, tab[1], b, list) : 0;
	(tab[1] != 0 || tab[2] != 0) ? quicksort_2(a, b, tab[1] + tab[2], list) : 0;
	free((void *)tab);
}

int			choose_rule_1(t_list **a, t_list **b, t_char **list)
{
	revers_rotate(a, list, 1);
	push(b, a, list, 1);
	return (1);
}

int			choose_2(t_list **a, t_list **b, t_char **list, int median)
{
	if ((*a)->digit >= median)
	{
		rotate(a, list, 1);
		return (1);
	}
	else if ((*a)->digit < median)
	{
		push(b, a, list, 1);
		return (-1);
	}
	return (0);
}

void		quicksort(t_list **a, t_list **b, int len, t_char **list)
{
	int		*tab;

	tab = arr_value_a(len, *a);
	if (len > 3)
		while (len > 0)
		{
			if (sort_median(*a, tab[4], len, 1) == 1)
			{
				if (lower(*a, tab[4]) == 1 && tab[3] == 0)
					tab[0] += choose_rule_1(a, b, list);
				else
					choose_2(a, b, list, tab[4]) == 1 ? tab[2]++ : tab[0]++;
			}
			else
				tab[1]++;
			len--;
		}
	else
		tab[2] = len;
	(tab[3] == 1 && tab[2] > 0) ? sorting_lower(1, tab[2], a, list) : 0;
	(tab[2] + tab[1] > 3) ? quicksort(a, b, tab[2] + tab[1], list) : 0;
	list_sort(a, tab[2] + tab[1], list);
	tab[0] != 0 ? quicksort_2(a, b, tab[0], list) : 0;
	free((void *)tab);
}
