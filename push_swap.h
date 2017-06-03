/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:45:54 by maksenov          #+#    #+#             */
/*   Updated: 2017/04/21 16:45:56 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define RED   "\x1B[31m"
# define BLU   "\x1B[34m"
# define CYN   "\x1B[36m"
# define GRN   "\x1B[32m"
# define END   "\x1B[0m"

# include "libft/libft.h"

typedef struct		s_char
{
	char			*line;
	struct s_char	*next;
}					t_char;

typedef struct		s_digit
{
	int				max;
	int				position_max;
	int				min;
	int				position_min;
}					t_digit;

typedef struct		s_flag
{
	int				flags;
	int				n;
	int				p1;
	int				p2;
}					t_flag;

void				*swap(t_list **list, t_char **line, int flag);
void				*push(t_list **list_a, t_list **list_b,
					t_char **line, int flag);
void				*rotate(t_list **list, t_char **line, int flag);
void				*revers_rotate(t_list **list, t_char **line, int flag);
t_list				*create_a(int len, char **av, int nb);
int					list_size(t_list *a);
void				play(t_list **a, t_list *b);
int					check_right(t_list *a);
void				*find_max_position(t_list *a, t_digit *digit);
void				find_max(t_list *a, t_digit *digit, int len);
void				find_min(t_list *a, t_digit *digit, int len);
void				*find_min_position(t_list *a, t_digit *digit);
int					find_position_median(t_list *a, int position_median);
int					find_median(t_list *a, int position_median,
					int len, int *median);
void				quicksort(t_list **a, t_list **b, int len, t_char **list);
void				list_sort(t_list **a, int len, t_char **list);
void				add(t_char **list, char *str);
void				change_list(t_char **list);
int					check_list_len(t_char *list);
void				print_list(t_char *list);
int					sort_median(t_list *list, int median, int len, int flag);
void				message(void);
int					change_char_del(t_char *list);
int					char_delete(t_char *list);
int					find_median_in_list(t_list *list, int len);
int					lower(t_list *list, int median);
void				sorting_lower(int size, int rotate_list,
					t_list **a, t_char **list);
int					*arr_value_a(int len, t_list *a);
int					*arr_value_b(int len, t_list *b);
void				check_stack_arr(t_char **arr, t_list **a, t_flag **flags);
void				print_stacks(t_list *a, t_list *b);
void				ok(void);
void				ko(void);
void				find_swap(char *str, t_list **a, t_list **b);
void				find_push(char *str, t_list **a, t_list **b);
void				find_rotate(char *str, t_list **a, t_list **b);
void				find_revers(char *str, t_list **a, t_list **b);
t_char				*create_stack(t_char *arr, t_list *a);
void				valid_arg(int len, char **av, t_list *list, int nb);
void				free_a(t_list **a);
void				free_arr(t_char **arr);
void				exit_b(t_list *b);
long long			ft_atoi_long(char *str);

#endif
