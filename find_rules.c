/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:33:42 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 15:33:44 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_swap(char *str, t_list **a, t_list **b)
{
	if (!ft_strcmp(str, "ss"))
	{
		swap(a, NULL, 0);
		swap(b, NULL, 0);
	}
	else if (!ft_strcmp(str, "sa"))
		swap(a, NULL, 0);
	else if (!ft_strcmp(str, "sb"))
		swap(b, NULL, 0);
}

void	find_push(char *str, t_list **a, t_list **b)
{
	if (!ft_strcmp(str, "pa"))
		push(a, b, NULL, 0);
	else if (!ft_strcmp(str, "pb"))
		push(b, a, NULL, 0);
}

void	find_rotate(char *str, t_list **a, t_list **b)
{
	if (!ft_strcmp(str, "rr"))
	{
		rotate(a, NULL, 0);
		rotate(b, NULL, 0);
	}
	else if (!ft_strcmp(str, "ra"))
		rotate(a, NULL, 0);
	else if (!ft_strcmp(str, "rb"))
		rotate(b, NULL, 0);
}

void	find_revers(char *str, t_list **a, t_list **b)
{
	if (!ft_strcmp(str, "rrr"))
	{
		revers_rotate(a, NULL, 0);
		revers_rotate(b, NULL, 0);
	}
	else if (!ft_strcmp(str, "rra"))
		revers_rotate(a, NULL, 0);
	else if (!ft_strcmp(str, "rrb"))
		revers_rotate(b, NULL, 0);
}
