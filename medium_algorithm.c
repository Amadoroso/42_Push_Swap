/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:54:13 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/20 17:25:33 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts with medium complexity algorithm. Chunk based.
t_stack	**ft_medium_algorithm(t_stack	**stack_head, t_info **info)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack_node	*traveller;
	int		chunk_size;
	int		search_limit;
	int		count;

	stack_a = *stack_head;
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	chunk_size = ft_sqrt(stack_a->size);
	search_limit = chunk_size;
	count = 0;
	while (stack_a->size)
	{
		while (count < search_limit && stack_a->size)
		{
			if (stack_a->top->index < search_limit)
			{
				ft_push_b(stack_a, stack_b);
				count++;
				ft_info_filler(stack_head, info, "pb");
			}
			else
			{
				ft_rotate(stack_a);
				ft_info_filler(stack_head, info, "ra");
			}
		}
		search_limit += chunk_size;
	}
	count = 0;
	while (stack_b->size)
	{
		traveller = stack_b->top;
		while (traveller->index != (stack_b->size - 1))
		{
			count++;
			traveller = traveller->next;
		}
		if (count >= stack_b->size / 2)
		{
			while (stack_b->top->index != traveller->index)
			{
				ft_reverse_b(stack_b);
				ft_info_filler(stack_head, info, "rrb");
			}
			ft_push_a(stack_a, stack_b);
			ft_info_filler(stack_head, info, "pa");
		}
		else if (count < stack_b->size / 2)
		{
			while (stack_b->top->index != traveller->index)
			{
				ft_rotate(stack_b);
				ft_info_filler(stack_head, info, "rb");
			}
			ft_push_a(stack_a, stack_b);
			ft_info_filler(stack_head, info, "pa");
		}
		count = 0;
	}
	ft_stack_clear(&stack_b);
	return (stack_head);
}

// calculates approximate floor (previous integer) of the square root
int	ft_sqrt(int	n)
{
	int	sqr;
	
	sqr = 0;
	while ((sqr * sqr) <= n)
		sqr++;
	return (sqr - 1);
}
