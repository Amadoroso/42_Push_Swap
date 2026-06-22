/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:54:13 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/21 17:05:42 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. Roughly orders by index in chunks of sqrt(size) in B. Scales n^1/2
void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int	count;
	int	chunk_size;
	int	search_limit;

	chunk_size = ft_sqrt((*stack_a)->size);
	search_limit = chunk_size;
	count = 0;
	while ((*stack_a)->size)
	{
		while (count < search_limit && (*stack_a)->size)
		{
			if ((*stack_a)->top->index < search_limit)
			{
				ft_push_b(*stack_a, *stack_b);
				count++;
				ft_info_filler(stack_a, info, "pb");
			}
			else
			{
				ft_rotate(*stack_a);
				ft_info_filler(stack_a, info, "ra");
			}
		}
		search_limit += chunk_size;
	}
}

// 2. Final ordering. Pushing to A according to index. Scales n
void	ft_final_sort(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int		count;
	int		highest_index;

	count = 0;
	while ((*stack_b)->size)
	{
		highest_index = ft_highest_index(stack_b, &count);
		if (count >= (*stack_b)->size / 2)
		{
			while ((*stack_b)->top->index != highest_index)
				ft_rotate_b_info(stack_a, stack_b, info, "rrb");
			ft_push_a_info(stack_a, stack_b, info);
		}
		else if (count < (*stack_b)->size / 2)
		{
			while ((*stack_b)->top->index != highest_index)
				ft_rotate_b_info(stack_a, stack_b, info, "rb");
			ft_push_a_info(stack_a, stack_b, info);
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
