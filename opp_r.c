/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:35:44 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/02 11:44:19 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a, t_node *first)
{
	ft_lstadd_back(stack_a, first);
	ft_printf("ra");
}

void	rb(t_node **stack_b, t_node *first)
{
	ft_lstadd_back(stack_b, first)
	ft_printf("rb");
}

void	rr(t_node **stack_a, t_node **stack_b, t_node *first_a, t_node *first_b)
{
	ft_lstadd_back(stack_a, first_a);
	ft_lstadd_back(stack_b, first_b);
	ft_printf("rr");
}
