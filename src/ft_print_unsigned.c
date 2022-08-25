/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquez <pmarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:32:51 by pmarquez          #+#    #+#             */
/*   Updated: 2022/06/16 10:29:08 by pmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_count_unsigned(unsigned int c)
{
	int	x;

	x = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		c += UINT_MAX + 1;
	while (c > 0)
	{
		c = c / 10;
		x++;
	}
	return (x);
}

void	ft_putnbr_unsigned_fd(unsigned int c, int fd)
{
	if (c < 0)
		c = c + UINT_MAX + 1;
	if (c <= 9)
		ft_putchar_fd(c + '0', fd);
	else if (c > 9)
	{
		ft_putnbr_fd(c / 10, fd);
		ft_putnbr_fd(c % 10, fd);
	}
}

int	ft_print_unsigned(unsigned int c)
{
	ft_putnbr_unsigned_fd(c, 1);
	return (ft_count_unsigned(c));
}
