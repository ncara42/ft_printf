/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:36:21 by ncaravac          #+#    #+#             */
/*   Updated: 2025/12/19 21:09:38 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	conversion(const char *format, int i, va_list args, int count)
{
	if (format[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (format[i] == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format[i] == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format[i] == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (format[i] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_print_loop(int count, int i, va_list args, const char *format)
{
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count = conversion(format, i, args, count);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_print_loop(0, 0, args, format);
	va_end(args);
	return (count);
}
