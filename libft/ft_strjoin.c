/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:58:31 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/11 21:16:11 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_s2;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s1_s2 = (char *) ft_calloc((len1 + len2 + 1),
			sizeof(char));
	if (s1_s2 == 0)
		return (NULL);
	ft_strlcpy(s1_s2, s1, len1 + 1);
	ft_strlcpy(s1_s2 + len1, s2, len2 + 1);
	return (s1_s2);
}

/* int main()
{
	char *joined;
	
	joined = ft_strjoin("OLA", "123");
	printf("%s", joined);
	free(joined);
} */
