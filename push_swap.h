/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:37:01 by oracio            #+#    #+#             */
/*   Updated: 2026/11/02 21:59:22 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft_printf.h"
# include "opps.h"

/* push_swap.c */
t_node	*create_stack_a(int argc, char **argv);

/* utils.c */
int		ft_atoi(char *str);
t_node	*ft_lstnew(int content, int i, t_node **stack_a);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);

/* utils_bis.c */
void	free_stack(t_node **stack);
void	set_index(t_node *stack);
int		stack_len(t_node *stack);

#endif
