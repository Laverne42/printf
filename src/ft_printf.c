/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquez <pmarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:38:00 by pmarquez          #+#    #+#             */
/*   Updated: 2022/06/16 10:29:18 by pmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
	{
		len += ft_print_char(va_arg(args, int));
	}
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		x;
	int		len;
	va_list	args;

	x = 0;
	len = 0;
	va_start(args, str);
	while (str[x] != '\0')
	{
		if (str[x] == '%')
		{
			len += ft_format(args, str[x + 1]);
			x++;
		}
		else
			len += ft_print_char(str[x]);
		x++;
	}
	va_end(args);
	return (len);
}
