/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:41:06 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:58:38 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy_custom(char *dst, const char *src, size_t start,
size_t end)
{
	size_t	index;

	index = 0;
	while (start <= end)
	{
		*(dst + index) = *(src + start);
		index++;
		start++;
	}
	*(dst + index) = 0;
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*set == '\0')
		return (result = ft_strdup(s1));
	if (*s1 == '\0')
		return (result = ft_strdup("\0"));
	start = 0;
	while (s1[start] != 0 && ft_strchr(set, s1[start]) != 0)
		start++;
	end = ft_strlen(s1) - 1;
	while (s1[end] != 0 && ft_strchr(set, s1[end]) != 0 && end != 0)
		end--;
	if (end < start)
		return (result = ft_strdup("\0"));
	result = malloc((end - start + 2) * sizeof(char));
	if (result == 0)
		return (NULL);
	return (result = ft_strcpy_custom(result, s1, start, end));
}

/*
int	main()
{
	char	*a;

	a = ft_strtrim("AAAAA", "xyz");
	printf("%s\n", a);
	free(a);
	return (0);
} */