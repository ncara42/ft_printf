/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaravac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 07:16:05 by ncaravac          #+#    #+#             */
/*   Updated: 2025/12/18 09:56:37 by ncaravac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_puthex(uintptr_t n, unsigned int upper);
int	ft_putptr(void *ptr);
int	ft_putunsigned(unsigned int n);
int	ft_print_loop(int count, int i, va_list args, const char *format);
int	conversion(const char *format, int i, va_list args, int count);

#endif
