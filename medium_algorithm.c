/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:54:13 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/22 15:43:01 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				ft_push_b(*a, *b);
				count++;
				ft_info_filler(a, info, "pb");
			}
			else
			{
				ft_rotate(*a);
				ft_info_filler(a, info, "ra");
			}
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
				ft_rb_info(a, b, info, "rrb");
			ft_pa_info(a, b, info);
		}
		else if (count < (*b)->size / 2)
		{
			while ((*b)->top->index != highest_index)
				ft_rb_info(a, b, info, "rb");
			ft_pa_info(a, b, info);
		}
		count = 0;
	}
}

// Sorts with medium complexity algorithm. Chunks of sqrt(size) based.
t_stack	**ft_medium_algorithm(t_stack	**stack_head, t_info **info)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = *stack_head;
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	ft_chunk_sort(&stack_a, &stack_b, info);
	ft_final_sort(&stack_a, &stack_b, info);
	ft_stack_clear(&stack_b);
	return (stack_head);
}
