/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:48:35 by ncaravac          #+#    #+#             */
/*   Updated: 2025/12/18 10:12:24 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_puthex(uintptr_t n, unsigned int upper)
{
	char	*hex;
	int		count;

	count = 0;
	if (upper)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, upper);
	count += ft_putchar(hex[n % 16]);
	return (count);
}
