/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:14:04 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/23 16:07:44 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer_printer(unsigned long long address, int fd)
{
	int	count;

	count = 0;
	if (address == 0)
		count += ft_putstr1_fd("(nil)", fd);
	else
	{
		count += ft_putstr1_fd("0x", fd);
		count += ft_putnbr_hex_address(address, fd, "0123456789abcdef");
	}
	return (count);
}

int	ft_formatter_check(char formatter, va_list args, int fd)
{
	int	count;

	count = 0;
	if (formatter == 'c')
		count = ft_putchar1_fd(va_arg(args, int), fd);
	else if (formatter == 's')
		count = ft_putstr1_fd(va_arg(args, char *), fd);
	else if (formatter == 'p')
		count = ft_pointer_printer(va_arg(args, unsigned long long), fd);
	else if (formatter == 'd' || formatter == 'i')
		count = ft_putnbr1_fd(va_arg(args, int), fd);
	else if (formatter == 'u')
		count = ft_putnbr_unsigned_fd(va_arg(args, unsigned int), fd);
	else if (formatter == 'x')
		count = ft_putnbr_hex(va_arg(args, unsigned int), fd, 'h');
	else if (formatter == 'X')
		count = ft_putnbr_hex(va_arg(args, unsigned int), fd, 'H');
	else if (formatter == '%')
		count = ft_putchar1_fd('%', fd);
	return (count);
}

int	ft_printf(int fd, const char *formatter, ...)
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
			count += ft_formatter_check(*formatter, args, fd);
		}
		else
		{
			ft_putchar1_fd(*formatter, fd);
			count++;
		}
		formatter++;
	}
	return (va_end(args), count);
}
