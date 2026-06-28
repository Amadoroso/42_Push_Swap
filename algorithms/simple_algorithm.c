/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:10:23 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/28 19:25:12 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_position(t_stack *stack)
{
	t_stack_node	*node;
	int				i;

	if (!stack)
		return ;
	node = stack->top;
	i = 0;
	while (node)
	{
		node->pos = i++;
		node = node->next;
	}
}

static int	ft_get_target_pos(t_stacks *stacks)
{
	t_stack_node	*node_a;
	int				target_pos;
	int				pos;

	ft_set_position(&stacks->a);
	node_a = stacks->a.top;
	target_pos = 0;
	pos = 0;
	while (node_a)
	{
		if (stacks->b.top->index > node_a->index)
			target_pos = pos + 1;
		pos++;
		node_a = node_a->next;
	}
	if (target_pos > stacks->a.size / 2)
		target_pos = target_pos - stacks->a.size;
	return (target_pos);
}

void	ft_execute_move_simple(t_stacks *stacks, t_info **info, int target_pos)
{
	while (target_pos > 0)
	{
		ft_rotate_a(&stacks->a, info);
		target_pos--;
	}
	while (target_pos < 0)
	{
		ft_reverse_a(&stacks->a, info);
		target_pos++;
	}
	ft_push_a(&stacks->a, &stacks->b, info);
}

void	ft_min_to_top(t_stacks *stacks, t_info **info)
{
	t_stack_node	*node;
	t_stack_node	*min_node;

	node = stacks->a.top;
	min_node = node;
	while (node)
	{
		if (node->index < min_node->index)
			min_node = node;
		node = node->next;
	}
	while (stacks->a.top != min_node)
	{
		ft_set_position(&stacks->a);
		if (min_node->pos < stacks->a.size / 2)
			ft_rotate_a(&stacks->a, info);
		else
			ft_reverse_a(&stacks->a, info);
	}
}

void	ft_simple_insertion_sort(t_stack **stack_a, t_stacks *stacks,
		t_info **info)
{
	while (stacks->a.size > 3)
		ft_push_b(&stacks->a, &stacks->b, info);
	ft_three_sort(&stacks->a, info);
	while (stacks->b.size > 0)
		ft_execute_move_simple(stacks, info, ft_get_target_pos(stacks));
	ft_min_to_top(stacks, info);
	(*stack_a)->top = stacks->a.top;
	(*stack_a)->size = stacks->a.size;
}
