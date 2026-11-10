/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extr_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:22:26 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/05 14:29:58 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_min_to_top(t_node **a)
{
	t_node	*min;
	int		n;
	int		i;

	set_index(*a);
	min = find_min(*a);
	n = stack_len(*a);
	i = min->index;
	if (min->abv_med)
	{
		while (i > 0)
		{
			ra(a);
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			rra(a);
			i++;
		}
	}
}

void	extr_min(t_node **a, t_node **b)
{
	while (*a)
	{
		bring_min_to_top(a);
		pb(b, a);
	}
	while (*b)
		pa(a, b);
}
