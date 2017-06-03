/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:12:07 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 17:12:08 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			char_delete(t_char *list)
{
	if (!ft_strcmp(list->line, "pa") && !ft_strcmp(list->next->line, "pb"))
		return (1);
	if (!ft_strcmp(list->line, "pb") && !ft_strcmp(list->next->line, "pa"))
		return (1);
	if (!ft_strcmp(list->line, "ra") && !ft_strcmp(list->next->line, "rra"))
		return (1);
	if (!ft_strcmp(list->line, "rra") && !ft_strcmp(list->next->line, "ra"))
		return (1);
	if (!ft_strcmp(list->line, "rb") && !ft_strcmp(list->next->line, "rrb"))
		return (1);
	if (!ft_strcmp(list->line, "rrb") && !ft_strcmp(list->next->line, "rb"))
		return (1);
	return (0);
}

int			change_char_del(t_char *list)
{
	if (!ft_strcmp(list->line, "sa") && !ft_strcmp(list->next->line, "sb"))
		return (1);
	if (!ft_strcmp(list->line, "sb") && !ft_strcmp(list->next->line, "sa"))
		return (1);
	if (!ft_strcmp(list->line, "ra") && !ft_strcmp(list->next->line, "rb"))
		return (1);
	if (!ft_strcmp(list->line, "rb") && !ft_strcmp(list->next->line, "ra"))
		return (1);
	if (!ft_strcmp(list->line, "rra") &&
			!ft_strcmp(list->next->line, "rrb"))
		return (1);
	if (!ft_strcmp(list->line, "rrb") &&
			!ft_strcmp(list->next->line, "rra"))
		return (1);
	return (0);
}

int			find_position_median(t_list *a, int position_median)
{
	int		median;

	median = 0;
	while (position_median-- > 0)
	{
		median = a->digit;
		a = a->next;
	}
	return (median);
}

int			find_median(t_list *a, int position_median, int len, int *median)
{
	int		flag;
	int		min;
	int		max;

	min = 0;
	max = 0;
	flag = 0;
	if (len % 2 == 0)
		flag = 1;
	*median = find_position_median(a, position_median);
	while (len-- > 0)
	{
		*median > a->digit ? min++ : 0;
		*median < a->digit ? max++ : 0;
		a = a->next;
	}
	if ((flag == 0 && min == max) || (flag == 1 && min - max == 1))
		return (1);
	return (0);
}

int			find_median_in_list(t_list *list, int len)
{
	int		position_median;
	int		median;

	position_median = 1;
	median = 0;
	while (find_median(list, position_median++, len, &median) == 0)
		;
	return (median);
}
