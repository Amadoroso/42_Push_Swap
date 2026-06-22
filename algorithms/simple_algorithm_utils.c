/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:00:00 by jtravanc          #+#    #+#             */
/*   Updated: 2026/06/22 22:11:54 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_stack_node	*find_max_node(t_stack *stack_a)
{
	t_stack_node	*node;
	t_stack_node	*max;

	node = stack_a->top;
	max = node;
	while (node != NULL)
	{
		if (node->index > max->index)
			max = node;
		node = node->next;
	}
	return (max);
}

void	ft_find_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*node_a;
	t_stack_node	*node_b;
	t_stack_node	*best;

	node_b = stack_b->top;
	while (node_b != NULL)
	{
		best = NULL;
		node_a = stack_a->top;
		while (node_a != NULL)
		{
			if (node_a->index > node_b->index)
			{
				if (best == NULL || best->index > node_a->index)
					best = node_a;
			}
			node_a = node_a->next;
		}
		if (best == NULL)
			best = find_max_node(stack_a);
		node_b->target = best;
		node_b = node_b->next;
	}
}

void	ft_set_position(t_stack *stack)
{
	int	mid;
	int	i;
	t_stack_node *node;
	
	if (!stack || !stack->top)
		return ;
	
	i = 0;
	node = stack->top;
	mid = stack->size / 2;

	while (node != NULL)
	{
		node->pos = i;
		if (i < mid)
			node->above_mid = 1;
		else
			node->above_mid = 0;
		node = node->next;
		i++;
	}
}

void	ft_calc_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node *node_b;
	
	ft_set_position (stack_a);
	ft_set_position (stack_b);
	node_b = stack_b->top;
	while(node_b != NULL)
	{
		if (node_b->above_mid)
			node_b->cost_b = node_b->pos;
		else
			node_b->cost_b = (stack_b->size - node_b->pos) * -1;
		if (node_b->target->above_mid)
			node_b->cost_a = node_b->target->pos;
		else
			node_b->cost_a = (stack_a->size - node_b->target->pos) * -1;
		node_b = node_b->next;
	}
}

t_stack_node	*ft_get_cheapest(t_stack *stack_b)
{
	t_stack_node	*node_b;
	t_stack_node	*cheapest;
	int				min_cost;
	int				total_cost;

	if (!stack_b || !stack_b->top)
		return (NULL);
	node_b = stack_b->top;
	cheapest = node_b;
	min_cost = INT_MAX;
	while (node_b != NULL)
	{
		total_cost = ft_abs(node_b->cost_a) + ft_abs(node_b->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = node_b;
		}
		node_b = node_b->next;
	}
	return (cheapest);
}