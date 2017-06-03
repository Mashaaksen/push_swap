#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maksenov <maksenov@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/21 15:35:45 by maksenov          #+#    #+#              #
#    Updated: 2017/04/21 15:35:48 by maksenov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_1 = push_swap

NAME_2 = checker

G = gcc

FLAG = -Wall -Wextra -Werror

SRC = add.c \
        check.c \
        chenge_list.c \
        error.c \
        find_all.c \
        find_in_list.c \
        play.c \
        push_swap.c \
        quicksort.c \
        sort.c \
        sorting.c \
        swap.c \
        checker.c \
        create.c \
        find_rules.c \
        print_stacks.c \
        valid.c

OBJ = $(SRC:.c=.o)

DEL = rm -rf

all: $(OBJ) $(NAME_1) $(NAME_2)

%.o: %.c
	$(G) $(FLAG) -c $<

$(NAME_1) :
	make -C libft/
	$(G) $(FLAG) add.o check.o chenge_list.o create.o find_rules.o error.o print_stacks.o find_all.o find_in_list.o play.o push_swap.o quicksort.o valid.o sort.o sorting.o swap.o libft/libft.a -o $(NAME_1)

$(NAME_2) :
	$(G) $(FLAG) check.o checker.o add.o error.o create.o find_rules.o print_stacks.o valid.o swap.o libft/libft.a -o $(NAME_2)

cleanlib:
	make -C libft/ clean

fcleanlib:
	make -C libft/ fclean

clean: cleanlib
	rm -f *.o

fclean: clean fcleanlib
	rm -f $(NAME_1) $(NAME_2)

re:	fclean all
