/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:14:04 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/08 12:17:10 by apinho-a         ###   ########.fr       */
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

/* #include <limits.h>
void    print_result(int std_len, int ft_len)
{
    if (std_len == ft_len)
        printf("    [OK] - Lengths Match: %d\n\n", ft_len);
    else
        printf("    [FAIL] - Mismatch! S:%d | Y:%d\n\n", std_len, ft_len);
}

int main(void)
{
    int     len1;
    int     ft_len1;
    int     test_var;
    char    *null_str;

    test_var = 42;
    null_str = NULL;
    
    printf("=== PART 1: INDIVIDUAL FORMAT SPECIFIERS ===\n\n");
    len1 = printf("Standard: %c, %c, %c\n", 'A', '0', '\n');
    ft_len1 = ft_printf("Yours   : %c, %c, %c\n", 'A', '0', '\n');
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: [%s] | Empty: [%s]\n", "Hello, 42!", "");
    ft_len1 = ft_printf("Yours   : [%s] | Empty: [%s]\n", "Hello, 42!", "");
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: %s\n", null_str);
    ft_len1 = ft_printf("Yours   : %s\n", null_str);
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: %d | %i | %d | %i\n", 123, 0, -456, INT_MIN);
    ft_len1 = ft_printf("Yours   : %d | %i | %d | %i\n", 123, 0, -456, INT_MIN);
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: %u | %u\n", 3000000000U, UINT_MAX);
    ft_len1 = ft_printf("Yours   : %u | %u\n", 3000000000U, UINT_MAX);
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: Low: %x | Up: %X | Zero: %x\n", 255, 3735928559U, 0);
    ft_len1 = ft_printf("Yours   : Low: %x | Up: %X | Zero: %x\n", 255, 3735928559U, 0);
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: %p | NULL: %p\n", &test_var, NULL);
    ft_len1 = ft_printf("Yours   : %p | NULL: %p\n", &test_var, NULL);
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: %%\n");
    ft_len1 = ft_printf("Yours   : %%\n");
    print_result(len1, ft_len1);
    
    printf("=== PART 2: EVALUATOR BOUNDARY CASES ===\n\n");
    len1 = printf("Standard: %d %i %u %x %X\n", 0, 0, 0, 0, 0);
    ft_len1 = ft_printf("Yours   : %d %i %u %x %X\n", 0, 0, 0, 0, 0);
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: Min: %d | Max: %d\n", INT_MIN, INT_MAX);
    ft_len1 = ft_printf("Yours   : Min: %d | Max: %d\n", INT_MIN, INT_MAX);
    print_result(len1, ft_len1);
    
    printf("=== PART 3: COMPLEX SENTENCES ===\n\n");
    len1 = printf("Standard: Char '%c' before str \"%s\" count %d.\n", 'A', "test", 100);
    ft_len1 = ft_printf("Yours   : Char '%c' before str \"%s\" count %d.\n", 'A', "test", 100);
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: Hex %x Upper %X Ptr %p!!\n", 26, 26, &test_var);
    ft_len1 = ft_printf("Yours   : Hex %x Upper %X Ptr %p!!\n", 26, 26, &test_var);
    print_result(len1, ft_len1);
    
    printf("=== PART 4: GET CRAZY MODE ===\n\n");
    len1 = printf("Standard: %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7);
    ft_len1 = ft_printf("Yours   : %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7);
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: %s %s %s\n", "one", "two", "three");
    ft_len1 = ft_printf("Yours   : %s %s %s\n", "one", "two", "three");
    print_result(len1, ft_len1);
    
    len1 = printf("Standard: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%p%%\n", 'X', "chaos", -1, 1, 4294967295U, 42, 42, &test_var);
    ft_len1 = ft_printf("Yours   : %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%p%%\n", 'X', "chaos", -1, 1, 4294967295U, 42, 42, &test_var);
    print_result(len1, ft_len1);
    
    return (0);
} */