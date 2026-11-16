/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:12:07 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/10 18:02:30 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_to_a(t_node **a, t_node **b, t_stats *s)
{
	t_node	*max;
	int		cost;

	if (!*b)
		return ;
	set_index(*b);
	max = find_max(*b);
	cost = find_cost(max, stack_len(*b));
	rotate_stack(b, cost, 'b', s);
	while (*b)
	{
		set_index(*a);
		(*b)->target = find_target_a(*b, *a);
		cost = find_cost((*b)->target, stack_len(*a));
		rotate_stack(a, cost, 'a', s);
		pa(a, b, s);
	}
	set_index(*a);
	rotate_stack(a, find_cost(find_min(*a), stack_len(*a)), 'a', s);
}

t_node	*find_target_a(t_node *src, t_node *a)
{
	t_node	*tmp;
	t_node	*best;

	best = NULL;
	tmp = a;
	while (tmp)
	{
		if (tmp->value > src->value && (!best || tmp->value < best->value))
			best = tmp;
		tmp = tmp->next;
	}
	if (!best)
		return (find_min(a));
	return (best);
}
