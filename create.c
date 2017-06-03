/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:08:34 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 17:08:35 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*create_a(int len, char **av, int nb)
{
	t_list	*head;
	t_list	*a;
	int		i;

	head = NULL;
	if (len - nb > 0)
	{
		i = (nb == 0 ? 1 : nb + 1);
		a = (len > 0 ? (t_list *)malloc(sizeof(t_list)) : NULL);
		head = a;
		nb != 0 ? len -= nb : 0;
		while (len-- > 0)
		{
			a->digit = ft_atoi(av[i++]);
			len != 0 ? a->next = (t_list *)malloc(sizeof(t_list)) : 0;
			len != 0 ? a = a->next : 0;
			len == 0 ? a->next = NULL : 0;
		}
	}
	return (head);
}

int			list_size(t_list *a)
{
	int		len;

	len = 0;
	while (a != NULL)
	{
		len++;
		a = a->next;
	}
	return (len);
}

t_char		*create_stack(t_char *arr, t_list *a)
{
	char	*str;

	str = NULL;
	while ((get_next_line(0, &str) != 0))
	{
		if (str == NULL)
			break ;
		if ((ft_strcmp(str, "ss") && ft_strcmp(str, "sa") &&
			ft_strcmp(str, "sb") && ft_strcmp(str, "pa") &&
			ft_strcmp(str, "pb") && ft_strcmp(str, "rr") &&
			ft_strcmp(str, "ra") && ft_strcmp(str, "rb") &&
			ft_strcmp(str, "rrr") && ft_strcmp(str, "rra") &&
			ft_strcmp(str, "rrb")) || a == NULL)
			message();
		add(&arr, str);
		free(str);
	}
	free(str);
	return (arr);
}
