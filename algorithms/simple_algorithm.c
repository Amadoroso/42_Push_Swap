/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:10:23 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/23 16:21:47 by apinho-a         ###   ########.fr       */
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

void	ft_simple_insertion_sort(t_stacks *stacks, t_info **info)
{
	t_stack_node	*node_a;
	int				target_pos;
	int				pos;

	while (stacks->a.size > 3)
		ft_push_b(&stacks->a, &stacks->b, info);
	ft_three_sort(&stacks->a, info);
	while (stacks->b.size > 0)
	{
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
		ft_execute_move_simple(stacks, info, target_pos);
	}
	ft_min_to_top(stacks, info);
}
