/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chenge_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:07:46 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 17:07:48 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		merge(t_char **list, char *str)
{
	t_char	*tmp;

	tmp = (*list)->next;
	(*list)->next = (*list)->next->next;
	free((*list)->line);
	(*list)->line = ft_strdup(str);
	tmp->next = NULL;
	free(tmp->line);
	free(tmp);
}

void		change_type(t_char **list, int *i)
{
	if (!ft_strcmp((*list)->line, "sa") || !ft_strcmp((*list)->line, "sb"))
		merge(list, "ss");
	else if (!ft_strcmp((*list)->line, "ra") ||
		!ft_strcmp((*list)->line, "rb"))
		merge(list, "rr");
	else if (!ft_strcmp((*list)->line, "rra") ||
		!ft_strcmp((*list)->line, "rrb"))
		merge(list, "rrr");
	(*i)++;
}

void		char_del(t_char **tail)
{
	t_char	*del1;
	t_char	*del2;

	del1 = (*tail)->next;
	del2 = (*tail)->next->next;
	(*tail)->next = (*tail)->next->next->next;
	del1->next = NULL;
	del2->next = NULL;
	free(del1->line);
	free(del2->line);
	free(del2);
	free(del1);
}

int			check_all_list(t_char **head, int i, t_char *list, t_char *tail)
{
	if (*head != NULL)
	{
		tail = *head;
		list = tail->next;
		while (1)
		{
			if (!list)
				break ;
			if (list->next && list->line && list->next->line
				&& char_delete(list))
			{
				i++;
				char_del(&tail);
			}
			else if (list->next && list->line && list->next->line &&
				change_char_del(list))
				change_type(&list, &i);
			else
			{
				tail = (list != NULL ? list : NULL);
				list = (tail->next != NULL ? list->next : NULL);
			}
		}
	}
	return (i);
}

void		change_list(t_char **head)
{
	t_char	*list;
	t_char	*tail;

	while (1)
	{
		list = NULL;
		tail = NULL;
		if (!check_all_list(head, 0, list, tail))
			break ;
	}
}
