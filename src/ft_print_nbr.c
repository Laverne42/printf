/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquez <pmarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:32:51 by pmarquez          #+#    #+#             */
/*   Updated: 2022/06/16 10:28:42 by pmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_count_nbr(int c)
{
	int	x;

	x = 0;
	if (c < 0)
	{
		c = c * -1;
		x = 1;
	}
	while (c > 0)
	{
		c = c / 10;
		x++;
	}
	return (x);
}

int	ft_print_nbr(int c)
{
	if (c == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (c == -2147483648)
	{
		ft_putnbr_fd(c, 1);
		return (11);
	}
	else
	{
		ft_putnbr_fd(c, 1);
		return (ft_count_nbr(c));
	}
}
