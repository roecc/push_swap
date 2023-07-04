# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 12:18:38 by ligabrie          #+#    #+#              #
#    Updated: 2023/07/04 13:41:37 by ligabrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror
LIBFT	:= ./libft/libft.a
SRCS	:= \
push_swap.c \
lst_utils.c \
push_swap_utils.c \
sort_three.c \
swap.c \
push.c \
rotate.c \
rev_rotate.c \
push_sort.c
OBJS	:= $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	@make -C ./libft 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)"
clean:
	@make clean -C ./libft 
	@rm -f $(OBJS)
fclean: clean
	@make fclean -C ./libft 
	@rm -f $(NAME) $(NAME_BONUS)
re: fclean all
.PHONY: all, clean, fclean, re
