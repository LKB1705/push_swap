/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: obohbot <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/02 11:38:25 by obohbot        #+#    #+#                */
/*   Updated: 2026/11/02 22:03:06 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*ft_lstpop_front(t_node **lst)
{
	t_node	*first;

	first = *lst;
	if (!first)
		return (NULL);
	*lst = first->next;
	if (*lst)
		(*lst)->prev = NULL;
	first->next = NULL;
	first->prev = NULL;
	return (first);
}

t_node	*ft_lstpop_back(t_node **lst)
{
	t_node	*last;

	last = ft_lstlast(*lst);
	if (!last)
		return (NULL);
	if (last->prev)
		last->prev->next = NULL;
	else
		*lst = NULL;
	last->prev = NULL;
	last->next = NULL;
	return (last);
}

void	set_index(t_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->abv_med = (i <= median);
		stack = stack->next;
		i++;
	}
}

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
