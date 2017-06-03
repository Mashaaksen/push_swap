/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:34:11 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 20:34:13 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		*swap(t_list **list, t_char **line, int flag)
{
	t_list	*tmp;

	tmp = *list;
	if (*list && (*list)->next)
	{
		*list = (*list)->next;
		tmp->next = (*list)->next;
		(*list)->next = tmp;
	}
	if (flag == 1)
		add(line, "sa");
	else if (flag == -1)
		add(line, "sb");
	return (NULL);
}

void		*push(t_list **list_a, t_list **list_b, t_char **line, int flag)
{
	t_list	*tmp;

	tmp = NULL;
	if (*list_b)
	{
		tmp = *list_b;
		*list_b = (*list_b)->next;
		tmp->next = *list_a;
		*list_a = tmp;
	}
	if (flag == 1)
		add(line, "pb");
	else if (flag == -1)
		add(line, "pa");
	return (NULL);
}

void		*rotate(t_list **list, t_char **line, int flag)
{
	t_list	*tmp;
	t_list	*p;

	p = *list;
	tmp = *list;
	if (*list && (*list)->next)
	{
		*list = (*list)->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
		p->next = NULL;
		tmp->next = p;
	}
	if (flag == 1)
		add(line, "ra");
	else if (flag == -1)
		add(line, "rb");
	return (NULL);
}

void		*revers_rotate(t_list **list, t_char **line, int flag)
{
	t_list	*tmp;
	t_list	*p;

	p = *list;
	tmp = *list;
	if (*list && (*list)->next)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			tmp->next == NULL ? p->next = NULL : 0;
			tmp->next != NULL ? p = p->next : 0;
		}
		tmp->next = *list;
		*list = tmp;
	}
	if (flag == 1)
		add(line, "rra");
	else if (flag == -1)
		add(line, "rrb");
	return (NULL);
}
