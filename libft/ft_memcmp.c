/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:29:53 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:52:35 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;	

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (*ptr1 == *ptr2 && --n > 0)
	{
		ptr1++;
		ptr2++;
	}
	return (*ptr1 - *ptr2);
}

/*
int	main()
{
	printf("%d\n", ft_memcmp("aaa123~", "aaa1234",7));
	printf("%d\n", memcmp("aaa123~", "aaa1234",7));
	return (0);
} */