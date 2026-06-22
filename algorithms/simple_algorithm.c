/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:10:23 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/22 22:10:25 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_execute_move(t_stack *stack_a, t_stack *stack_b,
		t_stack_node *cheapest)
{
	if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		ft_rotate_both(stack_a, stack_b, cheapest);
	else if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		ft_rev_rotate_both(stack_a, stack_b, cheapest);
	while (cheapest->cost_a > 0)
	{
		ft_rotate_a(stack_a);
		cheapest->cost_a--;
	}
	while (cheapest->cost_a < 0)
	{
		ft_reverse_a(stack_a);
		cheapest->cost_a++;
	}
	while (cheapest->cost_b > 0)
	{
		ft_rotate_b(stack_b);
		cheapest->cost_b--;
	}
	while (cheapest->cost_b < 0)
	{
		ft_reverse_b(stack_b);
		cheapest->cost_b++;
	}
	ft_push_a(stack_a, stack_b);
}

void	ft_min_to_top(t_stack *stack_a)
{
	t_stack_node	*node;
	t_stack_node	*min_node;
	int				min_index;

	ft_set_position(stack_a);
	node = stack_a->top;
	min_node = node;
	min_index = INT_MAX;
	while (node != NULL)
	{
		if (node->index < min_index)
		{
			min_index = node->index;
			min_node = node;
		}
		node = node->next;
	}
	while (stack_a->top != min_node)
	{
		if (min_node->above_mid)
			ft_rotate_a(stack_a);
		else
			ft_reverse_a(stack_a);
	}
}

void	ft_insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cheapest;

	while (stack_a->size > 3)
		ft_push_b(stack_a, stack_b);
	

	ft_three_sort(stack_a);
	
	while (stack_b->size > 0)
	{
		ft_find_target(stack_a, stack_b);
		ft_calc_cost(stack_a, stack_b);
		cheapest = ft_get_cheapest(stack_b);
		ft_execute_move(stack_a, stack_b, cheapest);
	}
	
	ft_min_to_top(stack_a);
}