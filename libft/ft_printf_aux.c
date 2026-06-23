/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:51:42 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/23 15:37:55 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr1_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_putstr1_fd("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		ft_putchar1_fd('-', fd);
		n = -n;
		count++;
	}
	if (n > 9)
		count += ft_putnbr1_fd ((n / 10), fd);
	count += ft_putchar1_fd((n % 10) + 48, fd);
	return (count);
}

int	ft_putnbr_hex(unsigned int n, int fd, char choice)
{
	char	*hex;
	int		count;

	if (choice == 'h')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	count = 0;
	if (n > 15)
		count += ft_putnbr_hex((n / 16), fd, choice);
	count += ft_putchar1_fd(hex[n % 16], fd);
	return (count);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned_fd((n / 10), fd);
	count += ft_putchar1_fd((n % 10) + 48, fd);
	return (count);
}

int	ft_putnbr_hex_address(unsigned long long n, int fd, char *hex)
{
	int	count;

	count = 0;
	if (n > 15)
		count += ft_putnbr_hex_address((n / 16), fd, hex);
	count += ft_putchar1_fd(hex[n % 16], fd);
	return (count);
}
