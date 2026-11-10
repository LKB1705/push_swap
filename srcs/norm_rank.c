/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_rank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:33:13 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/05 11:56:44 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Le but de ce file est de remplacer les value des node de la stack_a par leur 
 * rang au sein de la liste trié. 
 * Par exemple: [42, -7, 1000, 3] la list resultante sera [2, 0, 3, 1].
 * Le but ici est de facilité le traitement des valuer sans devoir gérer 
 * les signe ou les grand nombres.*/

#include "push_swap.h"

t_node	*value_to_rank(t_node *a)
{
	t_node	*i;
	t_node	*j;
	int		r;

	i = a;
	while (i)
	{
		r = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				r++;
			j = j->next;
		}
		i->value = r;
		i = i->next;
	}
	return (a);
}
