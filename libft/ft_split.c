/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:34:11 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/11 18:27:37 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(char const *s, char c)
{
	int	word_counter;
	int	in_word;

	word_counter = 0;
	in_word = 0;
	while (*s != 0)
	{
		if (*s == c)
			in_word = 0;
		if (*s != c && in_word == 0)
		{
			word_counter++;
			in_word = 1;
		}
		s++;
	}
	return (word_counter);
}

static char	**ft_calloc_error_handler(char **ptr_strings, int index_ptr)
{
	while (index_ptr >= 0)
	{
		free(*(ptr_strings + index_ptr));
		index_ptr--;
	}
	free(ptr_strings);
	return (NULL);
}

static int	ft_string_filler(char **string, char const *s, int j, int i)
{
	int	k;

	k = 0;
	while (k < j)
	{
		*(*string + k) = s[i];
		k++;
		i++;
	}
	return (i);
}

char static	**ft_split_actual(char **ptr_strings, char const *s,
						char c, int index_ptr)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			break ;
		j = 0;
		while (s[i + j] != c && s[i + j] != 0)
			j++;
		string = (char *) ft_calloc(j + 1, sizeof(char));
		if (!string)
			return (ft_calloc_error_handler(ptr_strings, index_ptr));
		*(ptr_strings + index_ptr) = string;
		index_ptr++;
		i = ft_string_filler(&string, s, j, i);
		j = 0;
	}
	return (ptr_strings);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_strings;
	int		word_counter;
	int		index_ptr;

	if (!s)
		return (NULL);
	word_counter = ft_word_counter(s, c);
	ptr_strings = (char **) ft_calloc(word_counter + 1, sizeof(char *));
	index_ptr = 0;
	if (!ptr_strings)
		return (NULL);
	return (ft_split_actual(ptr_strings, s, c, index_ptr));
}

/* int	main ()
{
	char **ptr_strings;
	int i;

	ptr_strings = ft_split("hello", 32);
	if (!ptr_strings)
		return (0);
	i = 0;
	while (ptr_strings[i] != 0)	
	{
		free(ptr_strings[i]);
		i++;
	}
	free(ptr_strings);
	return (0);
} */