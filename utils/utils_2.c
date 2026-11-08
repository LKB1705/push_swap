/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:50:47 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/06 13:00:07 by obohbot          ###   ########.fr       */
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

t_node	*find_target_b(t_node *src, t_node *b)
{
	t_node	*tmp;
	t_node	*best;

	best = NULL;
	tmp = b;
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