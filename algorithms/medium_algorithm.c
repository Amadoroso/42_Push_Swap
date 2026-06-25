/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:54:13 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/25 17:48:56 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 1. Roughly orders by index in chunks of sqrt(size) in B. Scales n^1/2
void	ft_chunk_sort(t_stack **a, t_stack **b, t_info **info)
{
	int	count;
	int	chunk_size;
	int	search_limit;

	chunk_size = ft_sqrt((*a)->size);
	search_limit = chunk_size;
	count = 0;
	while ((*a)->size)
	{
		while (count < search_limit && (*a)->size)
		{
			if ((*a)->top->index < search_limit)
			{
				ft_push_b(*a, *b, info);
				count++;
			}
			else
				ft_rotate_a(*a, info);
		}
		search_limit += chunk_size;
	}
}

// 2. Final ordering. Pushing to A according to index. Scales n
void	ft_final_sort(t_stack **a, t_stack **b, t_info **info)
{
	int		count;
	int		highest_index;

	count = 0;
	while ((*b)->size)
	{
		highest_index = ft_highest_index(b, &count);
		if (count >= (*b)->size / 2)
		{
			while ((*b)->top->index != highest_index)
				ft_reverse_b(*a, *b, info);
			ft_push_a(*a, *b, info);
		}
		else if (count < (*b)->size / 2)
		{
			while ((*b)->top->index != highest_index)
				ft_rotate_b(*a, *b, info);
			ft_push_a(*a, *b, info);
		}
		count = 0;
	}
}

// Sorts with medium complexity algorithm. Chunks of sqrt(size) based.
t_stack	**ft_medium_algorithm(t_stack	**stack_a, t_info **info)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = ft_calloc(1, sizeof(t_stack));
	if (!b)
		return (NULL);
	ft_chunk_sort(&a, &b, info);
	ft_final_sort(&a, &b, info);
	ft_stack_clear(&b);
	return (stack_a);
}
