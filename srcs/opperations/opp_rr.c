/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:36:14 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/02 21:04:00 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstpop_back(stack);
	ft_lstadd_front(stack, last);
}

void	rra(t_node **a, t_stats *s)
{
	reverse_rotate(a);
	ft_printf("rra\n");
	s->ops[OP_RRA]++;
}

void	rrb(t_node **b, t_stats *s)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
	s->ops[OP_RRB]++;
}

void	rrr(t_node **a, t_node **b, t_stats *s)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
	s->ops[OP_RRR]++;
}
