/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:55:02 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/04 13:56:17 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPPS_H
# define OPPS_H

# include "ft_printf.h"

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

/* opp_s.c */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

/* opp_p.c */
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);

/* opp_r.c */
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

/* opp_rr.c */
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/*pop front et back*/
t_node	*ft_lstpop_front(t_node **lst);
t_node	*ft_lstpop_back(t_node **lst);

/*add front et back*/
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);

#endif
