/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_routing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtravanc <jtravanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:02:37 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/25 17:45:46 by jtravanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// chooses the sorting algorithm to be used
void	ft_algorithm_routing(t_stack **stack_a, t_info **info, t_stacks *stacks)
{
	if (!(*info)->disorder)
		return ;
	else if (!ft_strcmp((*stack_a)->flag, "Simple / O(n2)"))
		ft_simple_insertion_sort(stack_a, stacks, info);
	else if (!ft_strcmp((*stack_a)->flag, "Medium / O(n√n)"))
		ft_medium_algorithm(stack_a, info);
	else if (!ft_strcmp((*stack_a)->flag, "Complex / O(nlogn)"))
		ft_radix_sort(*stack_a, info);
	else if (!ft_strncmp((*stack_a)->flag, "Adaptive", 8))
	{
		if (!ft_strcmp((*stack_a)->flag + 11, "O(n2)"))
			ft_simple_insertion_sort(stack_a, stacks, info);
		else if (!ft_strcmp((*stack_a)->flag + 11, "O(n√n)"))
			ft_medium_algorithm(stack_a, info);
		else if (!ft_strcmp((*stack_a)->flag + 11, "O(nlogn)"))
			ft_radix_sort(*stack_a, info);
	}
}
