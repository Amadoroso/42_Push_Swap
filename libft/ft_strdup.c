/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:57:33 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:54:54 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dup;
	unsigned int	index;

	dup = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == 0)
		return (NULL);
	index = 0;
	while (*s)
	{
		*(dup + index) = *s;
		s++;
		index++;
	}
	*(dup + index) = 0;
	return (dup);
}

/*
int	main()
{
	char 			*dup;
	char			*dup_2;
	unsigned int	index;

	dup = ft_strdup("02 s");
	dup_2 = strdup("02 s");

	index = 0;
	while (*(dup + index))
		write(1, dup + index++, 1);
	index = 0;
	write(1, "\n", 1);
	while (*(dup_2 + index))
		write(1, dup_2 + index++, 1);
	free(dup);
	free(dup_2);	
	return (0);
} */