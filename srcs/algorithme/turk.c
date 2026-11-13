/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:20:14 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/09 18:01:42 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk(t_node **a, t_node **b, t_stats *s)
{
	if (stack_len(*a) == 2)
	{
		sa(a, s);
		return ;
	}
	if (stack_len(*a) > 3)
		pb(b, a, s);
	if (stack_len(*a) > 3)
		pb(b, a, s);
	while (stack_len(*a) > 3)
	{
		set_index(*a);
		set_index(*b);
		set_cost(*a, *b);
		make_move(a, b, find_cheapest(*a), s);
	}
	sort_three(a, s);
	back_to_a(a, b, s);
}

void	make_move(t_node **a, t_node **b, t_node *cheapest, t_stats *s)
{
	int	a_cost;
	int	b_cost;
	int	common;

	a_cost = find_cost(cheapest, stack_len(*a));
	b_cost = find_cost(cheapest->target, stack_len(*b));
	if (a_cost > 0 && b_cost > 0)
	{
		common = min_int(a_cost, b_cost);
		call_rotation(a, b, common, s);
		a_cost -= common;
		b_cost -= common;
	}
	else if (a_cost < 0 && b_cost < 0)
	{
		common = min_int(-a_cost, -b_cost);
		call_rotation(a, b, -common, s);
		a_cost += common;
		b_cost += common;
	}
	rotate_stack(a, a_cost, 'a', s);
	rotate_stack(b, b_cost, 'b', s);
	pb(b, a, s);
}

void	call_rotation(t_node **a, t_node **b, int common, t_stats *s)
{
	while (common > 0)
	{
		rr(a, b, s);
		common--;
	}
	while (common < 0)
	{
		rrr(a, b, s);
		common++;
	}
}

void	rotate_stack(t_node **stack, int cost, char name, t_stats *s)
{
	while (cost > 0)
	{
		if (name == 'a')
			ra(stack, s);
		else
			rb(stack, s);
		cost--;
	}
	while (cost < 0)
	{
		if (name == 'a')
			rra(stack, s);
		else
			rrb(stack, s);
		cost++;
	}
}
