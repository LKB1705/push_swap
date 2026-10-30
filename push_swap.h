/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oracio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:37:01 by oracio            #+#    #+#             */
/*   Updated: 2026/10/29 16:36:46 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int		value;
	int		index;
	int		cost;
	int		abv_med;
	int		chpst;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node  *create_stack_a(int argc, char **argv);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int content, int   i, t_node **stack_a);
void    free_stack(t_node **stack);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
int	ft_atoi(char *str);

#endif
