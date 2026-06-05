/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:37:35 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/05 17:22:51 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks for repetitions
int	ft_repetition_check(int atoi_result, t_stack **stack_head)
{
	int				rep;
	t_stack_node	*traveller;

	if (!stack_head)
		return (1);
	traveller = (*stack_head)->top;
	rep = 0;
	while (traveller)
	{
		if(atoi_result == traveller->nbr)
			rep++;
		traveller = traveller->next;
	}
	return (rep);
}

// Checks if the passed value is whitespace
int	ft_iswspace(int	c)
{
	if(c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

// Detects and converts all wspaces to ' ' (32)
int	ft_sanitize_wspaces(char **argv, int i)
{
	int	j;
	int	wspace_count;
	
	j = 0;
	wspace_count = 0;
	while (argv[i][j])
	{
		if (ft_iswspace(argv[i][j]))
		{
			*(*(argv + i) + j) = ' ';
			wspace_count++;
		}
		j++;
	}
	return (wspace_count);
}

// If there are any white space chars, it splits the arg into several strings
char	**ft_sanitize(char **argv, int i)
{
	char	**new_args;
	if (ft_sanitize_wspaces(argv, i))
	{
		new_args = ft_split(argv[i], ' ');
		return (new_args);
	}
	else
		return (NULL);
}

// Creates the stack from the arguments. If error -> Frees(all) + returns(NULL)
t_stack	**ft_stack_creator(char **argv, t_stack **stack_head)
{
	int				atoi_check;
	int				atoi_result;
	int				i;
	int				j;
	int				index_i;
	int				index_j;
	t_stack_node	*new_node;
	char			**new_args;
	
	i = 0;
	index_i = 0;
	index_j = 0;
	while (*(argv + i) != 0)
	{
		new_args = ft_sanitize(argv, i);
		j = 0;
		if (!new_args)
		{
			atoi_result = ft_atoi(*(argv + i), &atoi_check);
			if (atoi_check == -1 || ft_repetition_check(atoi_result, stack_head) > 0)
				return(ft_stack_clear(stack_head), NULL);
			else
			{
				new_node = ft_node_new(index_i + index_j, atoi_result);
				if (!new_node)
					return (ft_stack_clear(stack_head), NULL);
				ft_stack_add(stack_head, new_node);	
			}
			index_i++;
		}
		else
		{
			while (*(new_args + j))
			{
				atoi_result = ft_atoi(*(new_args + j), &atoi_check);
				if (atoi_check == -1 || ft_repetition_check(atoi_result, stack_head) > 0)
					return(ft_stack_clear(stack_head), NULL);
				else
				{
					new_node = ft_node_new(index_i + index_j, atoi_result);
					if (!new_node)
						return (ft_stack_clear(stack_head), NULL);
					ft_stack_add(stack_head, new_node);	
				}
				j++;
				index_j++;
			}
		}
		i++;
	}
	(*stack_head)->size = index_j + index_i;
	return (stack_head);
}

// Parsing through argv arguments
t_stack	*ft_argv_parser(int argc, char **argv)
{
	t_stack	*stack_head;

	if (argc <= 1)
	return (NULL);
	stack_head = ft_calloc(1, sizeof(t_stack));
	argv++;
	if (!ft_stack_creator(argv, &stack_head))
		return (NULL);
	return (stack_head);
}


