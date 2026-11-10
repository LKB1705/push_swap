/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:28:07 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/09 12:28:19 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	find_cost(t_node *node, int len)
{
	if (node->abv_med)
		return (node->index);
	return (-(len - node->index));
}

void	set_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->target = find_target(a, b);
		cost_a = find_cost(a, len_a);
		cost_b = find_cost(a->target, len_b);
		if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
			a->cost = max_int(abs_int(cost_a), abs_int(cost_b));
		else
			a->cost = abs_int(cost_a) + abs_int(cost_b);
		a = a->next;
	}
}

t_node	*find_cheapest(t_node *a)
{
	t_node	*cheapest;

	cheapest = a;
	while (a)
	{
		if (a->cost < cheapest->cost)
			cheapest = a;
		a = a->next;
	}
	return (cheapest);
}
