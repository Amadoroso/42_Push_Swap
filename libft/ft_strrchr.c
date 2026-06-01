/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:31:11 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/08 15:28:27 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (*(s + len))
		len++;
	while (len >= 0)
	{
		if (*(s + len) == (char) c)
			return ((char *) s + len);
		len--;
	}
	return (0);
}

/*
int	main()
{
	printf("%s\n", ft_strrchr("aaaaBaaaa1aa", 49));
	printf("%p\n", ft_strrchr("aaaaBaaaa1aa", 49));
	printf("%s\n", strrchr("aaaaBaaaa1aa", 49));
	printf("%p\n", strrchr("aaaaBaaaa1aa", 49));
} */