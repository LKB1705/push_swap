/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:50:47 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/09 18:03:54 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_node	*find_min(t_node *stack)
{
	t_node	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_node	*find_target(t_node *src, t_node *b)
{
	t_node	*tmp;
	t_node	*best;

	best = NULL;
	tmp = b;
	set_index(b);
	while (tmp)
	{
		if (tmp->value < src->value && (!best || tmp->value > best->value))
			best = tmp;
		tmp = tmp->next;
	}
	if (!best)
		return (find_max(b));
	return (best);
}

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z)
		rra(a);
}
