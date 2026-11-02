/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utils.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: obohbot <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/02 11:24:32 by obohbot        #+#    #+#                */
/*   Updated: 2026/11/02 11:26:54 by obohbot        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->index = 0;
	new->prev = NULL;
	new->next = *lst;
	*lst = new;
	while (lst->next != NULL || lst->next == NULL)
	{
		if (lst->next == NULL)
			return ;
		lst = lst->next;
		lst->index += 1;
	}
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	last = ft_lstlast(*lst);
	if (!last)
	{
		*lst = new;
		new->index = 0;
	}
	else
	{
		last->next = new;
		new->prev = last;
		new->index = last->index + 1;
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
		lst->index -= 1;
	}
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*ft_lstnew(int content, int i, t_node **stack_a)
{
	t_node	*stack_n;

	stack_n = malloc(sizeof (t_node));
	if (!stack_n)
	{
		free_stack(stack_a);
		return (NULL);
	}
	stack_n->value = content;
	stack_n->index = i - 1;
	stack_n->cost = 0;
	stack_n->abv_med = 0;
	stack_n->chpst = 0;
	stack_n->target = NULL;
	stack_n->next = NULL;
	stack_n->prev = NULL;
	return (stack_n);
}
