/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:14:39 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/25 17:48:28 by jtravanc         ###   ########.fr       */
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

static void	radix_pass(t_stack *a, t_stack *b, int bit, t_info **info)
{
	int	j;
	int	size;

	j = 0;
	size = a->size;
	while (j < size)
	{
		if (((a->top->index >> bit) & 1) == 1)
			ft_rotate_a(a, info);
		else
			ft_push_b(a, b, info);
		j++;
	}
	while (b->size > 0)
		ft_push_a(a, b, info);
}

void	ft_radix_sort(t_stack *stack_a, t_info **info)
{
	t_stack	*stack_b;
	int		i;

	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return ;
	i = 0;
	while (i < get_max_bits(stack_a))
	{
		radix_pass(stack_a, stack_b, i, info);
		i++;
	}
	ft_stack_clear(&stack_b);
}
