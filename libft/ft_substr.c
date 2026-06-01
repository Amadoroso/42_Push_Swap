/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:42:33 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 14:00:01 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (sub = (char *) ft_calloc (1, sizeof(char)));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *) ft_calloc (len + 1, sizeof(char));
	if (sub == 0)
		return (NULL);
	index = 0;
	while (*(s + start + index) != 0 && len-- > 0)
	{
		*(sub + index) = *(s + start + index);
		index++;
	}
	return (sub);
}

/*
int main()
{
	char const *str;
	char *sub_str;
	str = "abcdefgh123456";
	sub_str = ft_substr(str, 3, 5);
	printf("%s", sub_str);
	free(sub_str);
} */