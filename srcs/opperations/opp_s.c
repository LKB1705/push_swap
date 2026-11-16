/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:34:23 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/02 21:09:45 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_node **a, t_stats *s)
{
	swap(a);
	ft_printf("sa\n");
	s->ops[OP_SA]++;
}

void	sb(t_node **b, t_stats *s)
{
	swap(b);
	ft_printf("sb\n");
	s->ops[OP_SB]++;
}

void	ss(t_node **a, t_node **b, t_stats *s)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
	s->ops[OP_SS]++;
}
