/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedal <lfedal@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:01:53 by lfedal            #+#    #+#             */
/*   Updated: 2026/11/15 22:36:56 by lfedal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include	"push_swap.h"

  static int max_bits(int max)
  {
	int bits;

	bits = 0;  
	while ((max >> bits) != 0)
	{
		bits++;
	}
	return (bits);
  }

  void	radix(t_node **a, t_node **b, t_stats *s)
  {

	int n;
	int j;
	int multi_bit;
	int bit;

	value_to_rank(*a);
	n = stack_len(*a);
	multi_bit = max_bits(n-1);

		bit = 0;
	while (bit < multi_bit)
	{
		j = 0;
		while (j < n)
		{
			if (((*a)->value >> bit) & 1)
				ra(a,s);     
			else
				pb(b, a, s);      
			j++;
		}
		while (*b)
			pa(a, b, s);        
		bit++;
	}
  }