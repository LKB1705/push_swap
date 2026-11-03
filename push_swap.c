/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oracio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:20:04 by oracio            #+#    #+#             */
/*   Updated: 2026/11/02 21:39:20 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stack_a(int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*stack_a;
	t_node	*stack_n;

	if (argc < 2)
		return (NULL);
	stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		stack_n = ft_lstnew(value, i, &stack_a);
		if (!stack_n)
			return (NULL);
		ft_lstadd_back(&stack_a, stack_n);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*tmp;

	stack_b = NULL;
	stack_a = create_stack_a(argc, argv);
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

/*A voir pour ajouter la creation de la stack_b*/
