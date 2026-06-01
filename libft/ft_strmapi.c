/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:56:56 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/08 15:28:18 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* static char	ft_capitalization_pairs(unsigned int index, char character)
{
	if (character >= 'a' && character <= 'z' && index % 2 == 0)
		character -= 32;
	return (character);
} */

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*s2;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	s2 = malloc (sizeof(char) * (len + 1));
	if (s2 == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(s2 + i) = (f(i, *(s + i)));
		i++;
	}
	*(s2 + i) = 0;
	return (s2);
}

/*
int	main()
{
	char	*str;
	
	str = ft_strmapi("abc", NULL);
	printf("%s\n", str);
	free(str);
	return (0);
} */