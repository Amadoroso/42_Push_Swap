/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:32:20 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/10 21:01:34 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *) big);
	j = 0;
	while (*(big + j) != 0 && j < len)
	{
		i = 0;
		if (*(big + j) == *(little + i))
		{
			while (*(big + j + i) == *(little + i) && j + i < len)
			{
				i++;
				if (*(little + i) == 0)
					return ((char *) big + j);
			}
		}
		j++;
	}
	return (0);
}

/*
int main()
{
	printf("%s\n",ft_strnstr("abc", "abcdef", 5));
	printf("%s\n",strnstr("abc", "abcdef", 5));
} */