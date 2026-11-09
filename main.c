/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:32:32 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/06 12:33:21 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*tmp;

	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	stack_a = value_to_rank(create_stack_a(argc, argv));
	extr_min(&stack_a, &stack_b);
	if (!stack_a)
		return (0);
	tmp = stack_a;
	while (tmp)
	{
		printf("value: %d, index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	free_stack(&stack_a);
	return (0);
}
