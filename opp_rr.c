/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:36:14 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/02 14:28:43 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **satck_a, t_node *last)
{
	ft_lstadd_front(stack_a, last);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b, t_node *last)
{
	ft_lstadd_front(stack_b, last);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b, t_node *last_a, t_node *last_b)
{
	ft_lstadd_front(satck_a, last_a);
	ft_lstadd_front(stack_b, last_b);
	ft_printf("rrr\n");
}
