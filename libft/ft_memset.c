/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:51:16 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/10 18:35:09 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c_char;
	unsigned char	*b_str;

	c_char = (unsigned char) c;
	b_str = (unsigned char *) b;
	while (len--)
		*b_str++ = c_char;
	return (b);
}

/*
int	main()
{
	unsigned char b_str[18] = "xxxxxxxxxxxxxxxxx";
	int	i;
	
	memset(b_str, 121, 5);
	i = 0;
	while(b_str[i] != 0)
		write(1,&b_str[i++],1);
	return(0);
} */