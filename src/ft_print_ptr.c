/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquez <pmarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:32:51 by pmarquez          #+#    #+#             */
/*   Updated: 2022/06/16 10:28:57 by pmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	count_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	while (ptr > 0)
	{
		ptr = ptr / 16;
		count++;
	}
	return (count);
}

int	ft_put_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
	return (count_ptr(ptr));
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	x;

	x = 1;
	if (ptr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
	{
		write(1, "0x", 2);
		x++;
	}
	ft_put_ptr(ptr);
	return (count_ptr(ptr) + x);
}
