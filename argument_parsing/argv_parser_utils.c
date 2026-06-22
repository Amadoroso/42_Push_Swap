/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:29:43 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/22 18:28:16 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks for repetitions
int	ft_repetition_check(int atoi_result, t_stack **stack_a)
{
	int				rep;
	t_stack_node	*traveller;

	if (!stack_a)
		return (1);
	traveller = (*stack_a)->top;
	rep = 0;
	while (traveller)
	{
		if (atoi_result == traveller->nbr)
			rep++;
		traveller = traveller->next;
	}
	return (rep);
}

// Checks if the passed value is whitespace
int	ft_iswspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

// Detects and converts all wspaces to ' ' (32)
int	ft_sanitize_wspaces(char *arg)
{
	int	j;
	int	wspace_count;

	j = 0;
	wspace_count = 0;
	while (*(arg + j))
	{
		if (ft_iswspace(*(arg + j)))
		{
			*(arg + j) = ' ';
			wspace_count++;
		}
		j++;
	}
	return (wspace_count);
}

// If there are any white space chars, it splits the arg into several strings
char	**ft_sanitize_and_split(char *arg)
{
	char	**new_args;

	if (ft_sanitize_wspaces(arg))
	{
		new_args = ft_split((const char *) arg, ' ');
		return (new_args);
	}
	else
		return (NULL);
}

// Frees the the full matrix that comes from ft_split
void	ft_split_free(char **matrix)
{
	int	i;

	i = 0;
	while (*(matrix + i))
	{
		free(*(matrix + i));
		i++;
	}
	free(matrix);
}
