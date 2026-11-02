/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp_s_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:34:23 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/02 14:28:27 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack)
{
	int	*tmp_0;
	int	*tmp_1;

	if (stack->next == NULL)
		return ;
	tmp_0 = stack->value;
	stack = stack->next;
	tmp_1 = stack->value;
	stack->value = tmp_0;
	stack = stack->prev;
	stack->value = tmp_1;
	ft_printf("sa\n");
}

void	sb(t_node **stack)
{
	int	*tmp_0;
	int	*tmp_1;

	if (stack->next == NULL)
		return ;
	tmp_0 = stack->value;
	stack = stack->next;
	tmp_1 = stack->value;
	stack->value = tmp_0;
	stack = stack->prev;
	stack->value = tmp_1;
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	int	*tmp_0;
	int	*tmp_1;	

	if (stack_a->next == NULL)
		return ;
	tmp_0 = stack_a->value;
	stack_a = stack_a->next;
	tmp_1 = stack_a->value;
	stack_a->value = tmp_0;
	stack_a = stack_a->prev;
	stack_a->value = tmp_1;
	if (stack_b->next == NULL)
		return ;
	tmp_0 = stack_b->value;
	stack_b = stack_b->next;
	tmp_1 = stack_b->value;
	stack_b->value = tmp_0;
	stack_b = stack_b->prev;
	stack_b->value = tmp_1;
	ft_printf("ss\n");
}

void	pa(t_node **stack_a, t_node *new)
{
	ft_lstadd_front(stack_a, new);
	ft_printf("pa\n");
}

void	pb(t_node **stack_b, t_node *new)
{
	ft_lstadd_front(stack_b, new);
	ft_printf("pb\n");
}
