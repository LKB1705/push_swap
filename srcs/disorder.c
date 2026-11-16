/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:08:15 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/04 12:40:39 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	comp_disorder(t_node *stack_a)
{
	t_node			*i;
	t_node			*j;
	unsigned int	mistakes;
	unsigned int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
