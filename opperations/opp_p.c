/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 21:10:07 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/02 21:43:41 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opps.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*node;

	if (!*src)
		return ;
	node = ft_lstpop_front(src);
	ft_lstadd_front(dst, node);
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
