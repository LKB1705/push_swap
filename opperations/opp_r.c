/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:35:44 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/02 19:02:44 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opps.h"

static void	rotate(t_node **stack)
{
	t_node	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = ft_lstpop_front(stack);
	ft_lstadd_back(stack, first);
}

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
