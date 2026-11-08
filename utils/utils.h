/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:17:13 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/06 15:17:34 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "opps.h"

/* utils.c */
int		ft_atoi(char *str);
t_node	*ft_lstnew(int content, int i, t_node **stack_a);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);

/* utils_1.c */
void	free_stack(t_node **stack);
void	set_index(t_node *stack);
int		stack_len(t_node *stack);
t_node	*ft_lstpop_front(t_node **lst);
t_node	*ft_lstpop_back(t_node **lst);

/* utils_2.c */
t_node	*find_min(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	*find_target_b(t_node *src, t_node *b);

#endif