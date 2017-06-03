/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:20:18 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 20:20:19 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		play(t_list **a, t_list *b)
{
	t_char	*list;

	list = NULL;
	quicksort(a, &b, list_size(*a), &list);
	change_list(&list);
	print_list(list);
	free_arr(&list);
	free_a(a);
}
