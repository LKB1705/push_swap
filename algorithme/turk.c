/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:20:14 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/06 14:54:54 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

void	turk(t_node **a, t_node **b)
{
	int	a_len;

	a_len = stack_len(*a);
	if (a_len > 3)
	{
		pb(b, a);
		pb(b, a);
	}
	else
	{
		/*sorting alogo simple a voir*/
	}
}

