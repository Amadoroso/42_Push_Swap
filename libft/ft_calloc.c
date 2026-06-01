/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:46:34 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/10 20:04:26 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	max_val;
	void	*result;

	max_val = -1;
	if (nmemb != 0 && size > max_val / nmemb)
		return (NULL);
	else
	{
		result = malloc (nmemb * size);
		if (!result)
			return (NULL);
		return (ft_memset(result, '\0', nmemb * size));
	}
}

/* int	main()
{
	int	*array_1;
	int	*array_2;
	size_t	nmeb;
	size_t	index;

	nmeb = 4;
	array_1 = (int *) ft_calloc (0, sizeof(NULL));
	array_2 = (int *) calloc (0, sizeof(NULL));
	index = 0;
	while (index < nmeb)
	{
		printf("%d", *(array_1 + index++));
		printf("%c", ' ');
	}
	printf("%c", '\n');
	index = 0;
	while (index < nmeb)
	{
		printf("%d", *(array_2 + index++));
		printf("%c", ' ');	
	}
	free(array_1);
	free(array_2);
	return (0);
} */