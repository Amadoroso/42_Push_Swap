/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:16:48 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/10 20:16:44 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd ((n / 10), fd);
	ft_putchar_fd((n % 10) + 48, fd);
}
/* #include <fcntl.h>
int main ()
{
	int fd;

	fd = open("a", O_RDWR | O_CREAT, 0644);
	ft_putnbr_fd(-245, fd);
	return (0);
} */