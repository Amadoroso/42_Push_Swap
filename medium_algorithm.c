/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:54:13 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/15 18:41:34 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts with medium complexity algorithm. Chunk based.
void	ft_medium_algorithm(t_stack	**stack_head, t_info **info)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		chunk_size;
	int		chunk_end;
	int		found;

	stack_a = *stack_head;
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	chunk_size = ft_sqrt(stack_a->size);
	chunk_end = chunk_size - 1;
	while (stack_a->size)
	{
		found = 0;
		while (found < chunk_size)
		{
			if (stack_a->top->index <= chunk_end)
			{
				ft_push_b(stack_a, stack_b);
				found++;
				ft_info_filler(&stack_head, &info, "pb");
			}
			else
			{
				ft_rotate_a(stack_a);
				ft_info_filler(&stack_head, &info, "ra");				
			}
		}
		chunk_end += chunk_size;
	}
	while (stack_b->size)
	{
		if ()
	}
	ft_stack_clear(stack_b);
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
