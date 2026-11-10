# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obohbot <obohbot@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 21:47:32 by obohbot           #+#    #+#              #
#    Updated: 2026/11/10 14:41:33 by obohbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
INC		= -I includes -I ft_printf

PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a
HEADERS		= includes/push_swap.h

SRCS = 		srcs/main.c \
			srcs/algorithme/extr_min.c \
			srcs/algorithme/turk.c \
			srcs/algorithme/turk_bis.c \
			srcs/opperations/opp_p.c \
			srcs/opperations/opp_r.c \
			srcs/opperations/opp_rr.c \
			srcs/opperations/opp_s.c \
			srcs/parser/parse.c \
			srcs/parser/parse_flag.c \
			srcs/utils/utils.c \
			srcs/utils/utils_1.c \
			srcs/utils/utils_2.c \
			srcs/utils/utils_cost.c \
			srcs/disorder.c \
			srcs/norm_rank.c \
			srcs/push_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
