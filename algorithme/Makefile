# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 15:02:58 by obohbot           #+#    #+#              #
#    Updated: 2026/11/06 15:07:44 by obohbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = algorithme.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = extr_min.c turk.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c algorithme.h
	$(CC) $(CFLAGS) -I ../opperations -I ../ft_printf -I ../utils -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
