/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 00:21:05 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/08 15:27:54 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static void	ft_capitalization_pairs(unsigned int index, char *c)
{
	if (*c >= 'a' && *c <= 'z' && index % 2 == 0)
		*c -= 32;
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		f(i, (s + i));
		i++;
	}
}

/*
int	main()
{
	char str[5] = "abcd";

	ft_striteri(str, ft_capitalization_pairs);
	printf("%s\n", str);
	
} */