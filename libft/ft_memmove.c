/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:23:45 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:53:04 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	count;

	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			*((unsigned char *) dest + n) = *((unsigned char *) src + n);
		}
	}
	else
	{
		count = 0;
		while (count < n)
		{
			*((unsigned char *) dest + count)
				= *((unsigned char *) src + count);
			count++;
		}
	}
	return (dest);
}

/*
int main()
{
	unsigned char src[14] = "Learningisfun";
	size_t	index;

	ft_memmove(src + 8, src, 2);

	index = 0;
	while (src[index])
		write(1, &src[index++], 1);
	return (0);
} */
