/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obohbot <obohbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 23:40:00 by obohbot           #+#    #+#             */
/*   Updated: 2026/11/12 23:40:00 by obohbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "push_swap.h"
 
void	init_stats(t_stats *s)
{
	int	i;
 
	i = 0;
	while (i < OP_COUNT)
	{
		s->ops[i] = 0;
		i++;
	}
}
 
void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}
 
void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;
 
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = nb % 10 + '0';
	write(fd, &c, 1);
}