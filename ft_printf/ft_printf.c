/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:14:04 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/08 16:25:41 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer_printer(unsigned long long address)
{
	int	count;

	count = 0;
	if (address == 0)
		count += ft_putstr1_fd("(nil)", 1);
	else
	{
		count += ft_putstr1_fd("0x", 1);
		count += ft_putnbr_hex_address(address, 1, "0123456789abcdef");
	}
	return (count);
}

static int	ft_formatter_check(char formatter, va_list args)
{
	int	count;

	count = 0;
	if (formatter == 'c')
		count = ft_putchar1_fd(va_arg(args, int), 1);
	else if (formatter == 's')
		count = ft_putstr1_fd(va_arg(args, char *), 1);
	else if (formatter == 'p')
		count = ft_pointer_printer(va_arg(args, unsigned long long));
	else if (formatter == 'd' || formatter == 'i')
		count = ft_putnbr1_fd(va_arg(args, int), 1);
	else if (formatter == 'u')
		count = ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	else if (formatter == 'x')
		count = ft_putnbr_hex(va_arg(args, unsigned int), 1, 'h');
	else if (formatter == 'X')
		count = ft_putnbr_hex(va_arg(args, unsigned int), 1, 'H');
	else if (formatter == '%')
		count = ft_putchar1_fd('%', 1);
	return (count);
}

int	ft_printf(const char *formatter, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!formatter)
		return (-1);
	va_start(args, formatter);
	while (*formatter)
	{
		if (*formatter == '%' && *(formatter + 1) != 0)
		{
			formatter++;
			count += ft_formatter_check(*formatter, args);
		}
		else
		{
			ft_putchar1_fd(*formatter, 1);
			count++;
		}
		formatter++;
	}
	return (va_end(args), count);
}
