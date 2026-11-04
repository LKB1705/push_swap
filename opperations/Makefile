# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obohbot <obohbot@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/04 13:39:45 by obohbot           #+#    #+#              #
#    Updated: 2026/11/04 13:51:52 by obohbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = opperation.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = opp_p.c opp_r.c opp_rr.c opp_s.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c opps.h
	$(CC) $(CFLAGS) -I ../ft_printf -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
