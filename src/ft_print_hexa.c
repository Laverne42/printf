/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquez <pmarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:32:51 by pmarquez          #+#    #+#             */
/*   Updated: 2022/06/16 10:28:37 by pmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	count_hexa(unsigned long long hexa)
{
	int	count;

	count = 0;
	if (hexa == 0)
		count = 1;
	while (hexa > 0)
	{
		hexa = hexa / 16;
		count++;
	}
	return (count);
}

int	ft_print_hexa(unsigned int hexa, char format)
{
	if (hexa >= 16)
	{
		ft_print_hexa(hexa / 16, format);
		ft_print_hexa(hexa % 16, format);
	}
	else
	{
		if (hexa <= 9)
			ft_putchar_fd((hexa + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((hexa - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((hexa - 10 + 'A'), 1);
		}
	}
	return (count_hexa(hexa));
}
