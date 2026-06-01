/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:03:33 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:52:21 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
	{
		if (*((unsigned char *) s) == (unsigned char) c)
			return ((void *) s);
		s++;
	}
	return (0);
}

/*
int main()
{
	printf("%s\n", (char *) ft_memchr("ola adeus", ' ', 20));
	printf("%p\n", (char *) ft_memchr("ola adeus", ' ', 20));
	printf("%s\n", (char *) memchr("ola adeus", ' ', 20));
	printf("%p\n", (char *) memchr("ola adeus", ' ', 20));
} */