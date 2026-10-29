/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oracio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:20:04 by oracio            #+#    #+#             */
/*   Updated: 2026/10/29 16:58:22 by oracio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stack_a(int argc, char **argv)
{
	int	i;
	int	value;
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
		ft_lstadd_back(&stack_a, stack_n);
		i++;
	}
	return (stack_a);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = create_stack_a(argc, argv);
	while (stack_a->next || stack_a->next == NULL)
	{
		printf("=================\n");
		printf("A l'adresse: %p\n", stack_a);
		printf("La value est: %d\n", stack_a->value);
		printf("L'index est: %d\n", stack_a->index);
		printf("La prochaine adresse est: %p\n", stack_a->next);
		printf("L'adresse précedente est: %p\n", stack_a->prev);
		stack_a = stack_a->next;
	}
	free_stack(&stack_a);
	return (0);
}
