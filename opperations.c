/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:34:23 by obohbot           #+#    #+#             */
/*   Updated: 2026/10/30 12:22:31 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_printf("sa");
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
	ft_printf("sb");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	int	*tmp_0;
	int	*tmp_1;
	
	//sa ----------------------
	if (stack_a->next == NULL)
		return ;
	tmp_0 = stack_a->value;
	stack_a = stack_a->next;
	tmp_1 = stack_a->value;
	stack_a->value = tmp_0;
	stack_a = stack_a->prev;
	stack_a->value = tmp_1;
	//sb ---------------------
	if (stack_b->next == NULL)
		return ;
	tmp_0 = stack_b->value;
	stack_b = stack_b->next;
	tmp_1 = stack_b->value;
	stack_b->value = tmp_0;
	stack_b = stack_b->prev;
	stack_b->value = tmp_1;
	ft_printf("ss");
}

void	pa()
{
	ft_printf("pa");
}

int	pb()
{
	ft_printf("pb");
}

int	ra()
{
	ft_printf("ra");
}

int	rb()
{
	ft_printf("rb");
}

int	rr()
{
	ft_printf("rr");
}

int	rra()
{
	ft_printf("rra");
}

int	rrb()
{
	ft_printf("rrb");
}

int	rrr()
{
	ft_printf("rrr");
}
