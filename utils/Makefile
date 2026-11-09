# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 15:15:20 by obohbot           #+#    #+#              #
#    Updated: 2026/11/06 15:16:50 by obohbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = utils.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = utils.c utils_1.c utils_2.c utils_cost.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c utils.h
	$(CC) $(CFLAGS) -I ../opperations -I ../ft_printf -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
