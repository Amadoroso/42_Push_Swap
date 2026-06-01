/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:54:33 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:53:07 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		*((unsigned char *) dest + index) = *((unsigned char *) src + index);
		index++;
	}
	return (dest);
}

/*
int	main()
{
	char *src ="abcdefghij";
	unsigned char dest[11] = "0123456789";
	unsigned int i;

	ft_memcpy(dest, src, 3);

	i = 0;
	while(dest[i])
		write(1, &dest[i++], 1);
	return (0);
} */