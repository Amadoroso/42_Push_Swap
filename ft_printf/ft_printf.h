/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:25:12 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/08 12:19:30 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *formatter, ...);
int	ft_putchar1_fd(char c, int fd);
int	ft_putstr1_fd(char *s, int fd);
int	ft_putnbr1_fd(int n, int fd);
int	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int	ft_putnbr_hex(unsigned int n, int fd, char choice);
int	ft_putnbr_hex_address(unsigned long long n, int fd, char *hex);

#endif