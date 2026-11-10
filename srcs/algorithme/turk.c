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

void	turk(t_node **a, t_node **b)
{
	int		a_len;

	a_len = stack_len(*a);
	if (a_len > 3)
	{
		pb(b, a);
		pb(b, a);
		while (stack_len(*a) > 3)
		{
			set_index(*a);
			set_index(*b);
			set_cost(*a, *b);
			make_move(a, b, find_cheapest(*a));
		}
	}
	sort_three(a);
}

void	make_move(t_node **a, t_node **b, t_node *cheapest)
{
	int	a_cost;
	int	b_cost;
	int	common;

	a_cost = find_cost(cheapest, stack_len(*a));
	b_cost = find_cost(cheapest->target, stack_len(*b));
	if (a_cost > 0 && b_cost > 0)
	{
		common = min_int(a_cost, b_cost);
		call_rotation(a, b, 1, common);
		a_cost -= common;
		b_cost -= common;
	}
	else if (a_cost < 0 && b_cost < 0)
	{
		common = min_int(-a_cost, -b_cost);
		call_rotation(a, b, -1, common);
		a_cost += common;
		b_cost += common;
	}
	signed_rotation(a, b, a_cost, b_cost);
	pb(b, a);
}

void	call_rotation(t_node **a, t_node **b, int sign, int common)
{
	while (common > 0)
	{
		if (sign == -1)
			rrr(a, b);
		else
			rr(a, b);
		common--;
	}
}

void	signed_rotation(t_node **a, t_node **b, int a_cost, int b_cost)
{
	rotate_stack(a, a_cost, 'a');
	rotate_stack(b, b_cost, 'b');
}

void	rotate_stack(t_node **stack, int cost, char name)
{
	while (cost > 0)
	{
		if (name == 'a')
			ra(stack);
		else
			rb(stack);
		cost--;
	}
	while (cost < 0)
	{
		if (name == 'a')
			rra(stack);
		else
			rrb(stack);
		cost++;
	}
}
