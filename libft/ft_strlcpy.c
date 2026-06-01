/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:07:19 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:56:08 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	index;

	len = 0;
	while (*(src + len))
		len++;
	if (size == 0)
		return (len);
	index = 0;
	while (index < (size - 1) && *src)
	{
		*dst++ = *src++;
		index++;
	}
	*dst = 0;
	return (len);
}

/*
int	main()
{
	char	dst[5];
	char	*src;
	size_t	i;

	src = "ola adeus";

	ft_strlcpy(dst, src, 5);

	i = 0;
	while(dst[i])
		write(1, &dst[i++], 1);
} */