/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:47:25 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 16:47:27 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add(t_char **list, char *str)
{
	t_char	*p;
	t_char	*tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = (t_char *)malloc(sizeof(t_char));
		while (((*list)->line = ft_strdup(str)) == NULL)
			;
		(*list)->next = NULL;
	}
	else if (*list != NULL)
	{
		p = (t_char *)malloc(sizeof(t_char));
		while ((p->line = ft_strdup(str)) == NULL)
			;
		p->next = NULL;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = p;
	}
}

int			check_list_len(t_char *list)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void		print_list(t_char *list)
{
	if (list)
	{
		while (list->next != NULL)
		{
			ft_putstr(list->line);
			ft_putstr("\n");
			list = list->next;
		}
		ft_putstr(list->line);
		ft_putstr("\n");
	}
}

int			sort_median(t_list *list, int median, int len, int flag)
{
	int		i;

	i = 0;
	while (len-- > 0)
	{
		if (flag == 1)
			list->digit < median ? i++ : 0;
		else if (flag == -1)
			list->digit > median ? i++ : 0;
		list = list->next;
	}
	return (i == 0 ? i : 1);
}
