# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 13:58:16 by ligabrie          #+#    #+#              #
#    Updated: 2023/07/01 14:40:22 by ligabrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = \
push_swap.c \
push_swap_utils.c \
push_sort.c \
sort_three.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc -Wall -Wextra -Werror
CC_FLAGS = -Llibft -lft

%.o:%.c
	$(CC) -c -o $@ $^
	
all:	libft $(NAME)

libft: 
	make -C libft
	
$(NAME): $(SOURCES) libft/libft.a
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f $(NAME) libft/libft.a
	make -C libft fclean

re:	fclean all

.PHONY: libft clean fclean re
