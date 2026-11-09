# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obohbot <obohbot@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 21:47:32 by obohbot           #+#    #+#              #
#    Updated: 2026/11/04 16:18:04 by obohbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

OPP_DIR = opperations
OPP		= $(OPP_DIR)/opperation.a

ALGO_DIR = algorithme
ALGO = $(ALGO_DIR)/algorithme.a

UTILS_DIR = utils
UTILS = $(UTILS_DIR)/utils.a

SRCS = push_swap.c norm_rank.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF) $(OPP) $(UTILS) $(ALGO) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(ALGO) $(UTILS) $(OPP) $(PRINTF) -o $(NAME)
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(OPP):
	$(MAKE) -C $(OPP_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

$(ALGO):
	$(MAKE) -C $(ALGO_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I $(PRINTF_DIR) -I $(OPP_DIR) -I $(UTILS_DIR) -I $(ALGO_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(OPP_DIR) clean
	$(MAKE) -C $(UTILS_DIR) clean
	$(MAKE) -C $(ALGO_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(OPP_DIR) fclean
	$(MAKE) -C $(UTILS_DIR) fclean
	$(MAKE) -C $(ALGO_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
