/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:10:20 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 17:10:22 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_min(t_list *a, t_digit *digit, int len)
{
	digit->min = 2147483647;
	while (len-- > 0)
	{
		digit->min > a->digit ? digit->min = a->digit : 0;
		a = a->next;
	}
}

void		*find_min_position(t_list *a, t_digit *digit)
{
	digit->position_min = 1;
	while (a != NULL)
	{
		if (a->digit == digit->min)
			return (NULL);
		digit->position_min++;
		a = a->next;
	}
	return (NULL);
}

void		find_max(t_list *a, t_digit *digit, int len)
{
	digit->max = -2147483648;
	while (len-- > 0)
	{
		a->digit > digit->max ? digit->max = a->digit : 0;
		a = a->next;
	}
}

void		*find_max_position(t_list *a, t_digit *digit)
{
	digit->position_max = 1;
	while (a != NULL)
	{
		if (a->digit == digit->max)
			return (NULL);
		digit->position_max++;
		a = a->next;
	}
	return (NULL);
}
