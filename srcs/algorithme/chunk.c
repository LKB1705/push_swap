/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 19:28:29 by lfedal            #+#    #+#             */
/*   Updated: 2026/11/15 22:37:53 by lfedal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	k;

	k = 1;
	while ((k + 1) * (k + 1) <= n)
		k++;
	return (k);
}

static void	push_chunks(t_node **a, t_node **b, t_stats *s, int k)
{
	int low;
	int hight;
	int need;

	low = 0;
		while (*a != NULL)
		{
			hight = low + k -1;
			need = k;
			if (need > stack_len(*a))
				need = stack_len(*a);
			while (need > 0)
			{
				if ((*a)->value >= low && (*a)->value <= hight)
				{
					pb(b, a, s);
					need--;
				}
				else
					ra(a, s);		
			}
			low = low + k;
		}
	}

static void	push_max(t_node **a, t_node **b, t_stats *s)
{
	t_node	*max;

	while (*b)
	{
		set_index(*b);
		max = find_max(*b);
		if (max->abv_med)
		{
			while (*b != max)
				rb(b,s);
		}
		else
		{
			while (*b != max)
				rrb(b, s);    
		}
		pa(a,b, s);       
	}
}

void	chunk_sort(t_node **a, t_node **b, t_stats *s)
{
	value_to_rank(*a);
	push_chunks(a, b, s, ft_sqrt(stack_len(*a)));
	push_max(a, b, s);
}


