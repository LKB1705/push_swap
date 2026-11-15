/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 18:35:43 by lfedal            #+#    #+#             */
/*   Updated: 2026/11/15 23:02:20 by lfedal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min(t_node **a, t_node **b, t_stats *s)
{
	t_node	*min;

	set_index(*a);
	min = find_min(*a);
	if (min->abv_med)
	{
		while (*a != min)
			ra(a, s);
	}
	else
	{
		while (*a != min)
			rra(a, s);
	}
	pb(b, a, s);
}

void	sort_small(t_node **a, t_node **b, t_stats *s)
{
	if (stack_len(*a) == 2)
	{
		sa(a, s);
		return ;
	}
	while (stack_len(*a) > 3)
		push_min(a, b, s);
	sort_three(a, s);
	while (*b)
		pa(a, b, s);
}