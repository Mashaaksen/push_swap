/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:38:20 by maksenov          #+#    #+#             */
/*   Updated: 2017/05/08 17:38:22 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_right(t_list *a)
{
	int		min;

	if (a != NULL)
	{
		min = a->digit;
		while (a != NULL)
		{
			a = a->next;
			if (a && min > a->digit)
				return (0);
			a != NULL ? min = a->digit : 0;
		}
	}
	return (1);
}

void		find_rules(t_char *arr, t_list **a, t_flag *flags)
{
	t_list	*b;

	b = NULL;
	while (arr != NULL)
	{
		if (!ft_strcmp(arr->line, "ss") || !ft_strcmp(arr->line, "sa")
			|| !ft_strcmp(arr->line, "sb"))
			find_swap(arr->line, a, &b);
		else if (!ft_strcmp(arr->line, "pa") || !ft_strcmp(arr->line, "pb"))
			find_push(arr->line, a, &b);
		else if (!ft_strcmp(arr->line, "rr") || !ft_strcmp(arr->line, "ra") ||
			!ft_strcmp(arr->line, "rb"))
			find_rotate(arr->line, a, &b);
		else if (!ft_strcmp(arr->line, "rrr") || !ft_strcmp(arr->line, "rra")
			|| !ft_strcmp(arr->line, "rrb"))
			find_revers(arr->line, a, &b);
		if (flags->p2 == 1 && *a != NULL)
			print_stacks(*a, b);
		arr = arr->next;
	}
	exit_b(b);
}

void		free_arr(t_char **arr)
{
	t_char	*tmp;

	tmp = NULL;
	while (*arr && (*arr)->next)
	{
		tmp = (*arr)->next;
		(*arr)->next = NULL;
		free((*arr)->line);
		free(*arr);
		*arr = tmp;
	}
	if (*arr)
	{
		free((*arr)->line);
		free(*arr);
	}
}

void		free_a(t_list **a)
{
	t_list	*tmp;

	tmp = NULL;
	while (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = NULL;
		free(*a);
		*a = tmp;
	}
	if (*a)
		free(*a);
}

void		check_stack_arr(t_char **arr, t_list **a, t_flag **flags)
{
	find_rules(*arr, a, *flags);
	if ((*flags)->p1 == 1 && *a != NULL)
		print_stacks(*a, NULL);
	if (check_right(*a) == 1)
		ok();
	else
		ko();
	if ((*flags)->n == 1 && *a != NULL)
	{
		ft_putstr(BLU);
		ft_putstr("Number of operations: ");
		ft_putnbr(check_list_len(*arr));
		ft_putstr(END);
		write(1, "\n", 1);
	}
	free(*flags);
	free_arr(arr);
	free_a(a);
}
