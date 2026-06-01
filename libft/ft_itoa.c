/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:56:28 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/08 15:24:32 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_len(int n)
{
	int	size_n;

	if (n <= 0)
		size_n = 1;
	else
		size_n = 0;
	while (n != 0)
	{
		n /= 10;
		size_n++;
	}
	return (size_n);
}

static	char	*ft_string_filler(char *nbr, int n, int size_n)
{
	*(nbr + size_n) = '\0';
	size_n--;
	if (n < 0)
	{
		while (size_n != 0)
		{
			*(nbr + size_n) = (char)(((n % 10) * -1) + 48);
			n = n / 10;
			size_n--;
		}
		*(nbr + size_n) = '-';
	}
	else
	{
		while (size_n >= 0)
		{
			*(nbr + size_n) = (char)((n % 10) + 48);
			n = n / 10;
			size_n--;
		}
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		size_n;

	size_n = ft_malloc_len(n);
	nbr = (char *) malloc (sizeof(char) * (size_n + 1));
	if (nbr == 0)
		return (NULL);
	return (ft_string_filler(nbr, n, size_n));
}

/*
int	main()
{
	char *nbr;

	nbr = ft_itoa(-2147483648);
	printf("%s\n",nbr);

	free(nbr);
	return 0;
} */