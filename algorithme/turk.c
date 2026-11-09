/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:20:14 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/09 12:53:52 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme.h"

void	turk(t_node **a, t_node **b)
{
	int		a_len;
	t_node	*tmp;

	a_len = stack_len(*a);
	tmp = a;
	if (a_len > 3)
	{
		pb(b, a);
		pb(b, a);
    while (stack_len(*a) > 3)
    {
		  while (tmp)
		  {
			  find_target(tmp, (*b));
			  tmp = tmp->next;
		  }
      set_cost(*a, *b);
      find_cheapest(*a);
      make_move(&a, &b);
    }
	}
}

void  make_move(t_node **a, t_node **b)
{
  int a_cost;
  int b_cost;
  int min;

  a_cost = find_cost(*a, stack_len(*a));
  b_cost = find_cost(*b, stack_len(*b));
  min = min_int(abs_int(a_cost), abs_int(b_cost));
  if (a_cost > 0 && b_cost > 0)
    call_rotation(&a, &b, 1, min);
  else if (a_cost < 0 && b_cost < 0)
    call_rotation(&a, &b, -1, min);
  else if ((a_cost < 0 && b_cost > 0) || (a_cost > 0 && b_cost < 0))
    
}

void  call_rotation(t_node **a, t_node **b, int sign, int min)
{
  if (sign == -1)
  {
    while (min > 0)
    {
      rrr(&a, &b);
      min--;
    }
  }
  else
  {
    while (min > 0)
    {
      rr(&a, &b);
      min--;
    }
  }
}

void  signed_rotation(t_node **a, t_node **b, int a_cost, int b_cost)
{
  int rot;

  //Rotation pour la stack_a
  if (a_cost < 0)
  {
    rot = -a_cost;
    while (rot > 0)
    {
      rra(&a);
      rot--;
    }
  }
  else if (a_cost > 0)
  {
    rot = a_cost;
    while (rot > 0)
    {
      ra(&a, &b);
      rot--,
    }
  }

  //Rotation pour la stack_a
  if (b_cost < 0)
  {
    rot = -b_cost;
    while (rot > 0)
    {
      rrb(&b, &b);
      rot--;
    }
  }
  else if (a_cost > 0)
  {
    rot = a_cost;
    while (rot > 0)
    {
      ra(&a, &b);
      rot--,
    }
  }


}
