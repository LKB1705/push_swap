/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:37:01 by oracio            #+#    #+#             */
/*   Updated: 2026/11/02 11:46:47 by obohbot        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				abv_med;
	int				chpst;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	*create_stack_a(int argc, char **argv);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int content, int i, t_node **stack_a);
void	free_stack(t_node **stack);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	pa(t_node **stack_a, t_node *new);
void	pb(t_node **stack_b, t_node *new);
void	ss(t_node **stack_a, t_node **stack_b);
void	sb(t_node **stack);
void	sa(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b, t_node *last_a, t_node *last_b);
void	rrb(t_node **stack_b, t_node *last);
void	rra(t_node **satck_a, t_node *last);
void	rr(t_node **stack_a, t_node **stack_b,
			t_node *first_a, t_node *first_b);
void	rb(t_node **stack_b, t_node *first);
void	ra(t_node **stack_a, t_node *first);
int		ft_atoi(char *str);

#endif
