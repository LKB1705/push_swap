# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obohbot <obohbot@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 21:47:32 by obohbot           #+#    #+#              #
#    Updated: 2026/11/02 21:48:47 by obohbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

SRCS		= push_swap.c utils.c utils_bis.c \
		  opp_s.c opp_p.c opp_r.c opp_rr.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I $(PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
