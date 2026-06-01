/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:21 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/08 15:44:33 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	start_dst;
	size_t	start_src;

	dst_len = 0;
	while (*(dst + dst_len))
		dst_len++;
	src_len = 0;
	while (*(src + src_len))
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	else
	{
		start_src = 0;
		start_dst = dst_len;
		while (start_src < size - 1 - dst_len && *(src + start_src))
			*(dst + start_dst++) = *(src + start_src++);
		*(dst + start_dst) = 0;
		return (dst_len + src_len);
	}
}

/* int	main()
{
	char	src[7] = "ABCDEF";
	char	dst[7] = "123456";
	size_t len;

	len = ft_strlcat(dst, src, 12);
	printf("%zu\n", len);
	printf("%s", dst);
	return (0);
} */

/* int main()
{
	char	*dst;
	size_t len;

	dst = (char *) malloc(sizeof(*dst) * 15);
	ft_memset(dst, 'r', 15);
	len = ft_strlcat(dst, "lorem ipsum dolor sit amet", 5);
	printf("%zu\n", len);
	printf("%s\n", dst);
	ft_memset(dst, 'r', 15);
	len = strlcat(dst, "lorem ipsum dolor sit amet", 5);
	printf("%zu\n", len);
	printf("%s\n", dst);
	free(dst);
	return (0);
} */