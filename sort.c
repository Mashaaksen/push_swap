/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:27:35 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 20:27:37 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_len_2(t_list **a, t_digit *digit, t_char **list)
{
	if (digit->position_max == 1)
		swap(a, list, 1);
}

void		sort_len_3_2(t_list **a, t_digit *digit, t_char **list)
{
	if (digit->position_min == 2 && digit->position_max == 1)
	{
		swap(a, list, 1);
		rotate(a, list, 1);
		swap(a, list, 1);
		revers_rotate(a, list, 1);
	}
	else if (digit->position_min == 1 && digit->position_max == 2)
	{
		rotate(a, list, 1);
		swap(a, list, 1);
		revers_rotate(a, list, 1);
	}
}

void		sort_len_3(t_list **a, t_digit *digit, t_char **list)
{
	if (digit->position_min == 2 && digit->position_max == 3)
		swap(a, list, 1);
	else if (digit->position_min == 3 && digit->position_max == 2)
	{
		rotate(a, list, 1);
		swap(a, list, 1);
		revers_rotate(a, list, 1);
		swap(a, list, 1);
	}
	else if (digit->position_min == 3 && digit->position_max == 1)
	{
		swap(a, list, 1);
		rotate(a, list, 1);
		swap(a, list, 1);
		revers_rotate(a, list, 1);
		swap(a, list, 1);
	}
	else
		sort_len_3_2(a, digit, list);
}

void		sort_len_3_1(t_list **a, t_digit *digit, t_char **list)
{
	if (digit->position_min == 2 && digit->position_max == 3)
		swap(a, list, 1);
	else if (digit->position_min == 3 && digit->position_max == 2)
		revers_rotate(a, list, 1);
	else if (digit->position_min == 3 && digit->position_max == 1)
	{
		swap(a, list, 1);
		revers_rotate(a, list, 1);
	}
	else if (digit->position_min == 2 && digit->position_max == 1)
		rotate(a, list, 1);
	else if (digit->position_min == 1 && digit->position_max == 2)
	{
		swap(a, list, 1);
		rotate(a, list, 1);
	}
}

void		list_sort(t_list **a, int len, t_char **list)
{
	t_digit	digit;

	if (len == 3 || len == 2)
	{
		find_min(*a, &digit, len);
		find_max(*a, &digit, len);
		find_min_position(*a, &digit);
		find_max_position(*a, &digit);
		if (len == 2)
			sort_len_2(a, &digit, list);
		else
		{
			if (list_size(*a) > 3)
				sort_len_3(a, &digit, list);
			else if (list_size(*a) == 3)
				sort_len_3_1(a, &digit, list);
		}
	}
}
