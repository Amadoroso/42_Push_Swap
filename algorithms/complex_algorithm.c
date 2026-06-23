/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:14:39 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/23 16:21:45 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// fuction to count how many bits we need to count the index 
static int	get_max_bits(t_stack *stack)
{
	int	max_index;
	int	max_bits;

	max_index = stack->size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b, t_info **info)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = stack_a->size;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->top->index >> i) & 1) == 1)
				ft_rotate_a(stack_a, info);
			else
				ft_push_b(stack_a, stack_b, info);
			j++;
		}
		while (stack_b->size > 0)
			ft_push_a(stack_a, stack_b, info);
		i++;
	}
}
