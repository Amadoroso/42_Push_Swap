/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_routing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:02:37 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/22 18:30:56 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// chooses the sorting algorithm to be used
void	ft_algorithm_routing(t_stack **stack_a, t_info **info)
{
	if (!(*info)->disorder)
		return ;
/*  	if (!ft_strcmp((*stack_a)->flag, "Simple / O(n2)"))
		// simple */
	else if (!ft_strcmp((*stack_a)->flag, "Medium / O(n√n)"))
		ft_medium_algorithm(stack_a, info);
/*  	else if (!ft_strcmp((*stack_a)->flag, "Complex / O(nlogn)"))
		// complex
	else if (!ft_strncmp((*stack_a)->flag, "Adaptive", 8))
	{
		if (!ft_strcmp((*stack_a)->flag + 10, "O(n2)"))
			// simple
		else if (!ft_strcmp((*stack_a)->flag + 10, "O(n√n)"))
			ft_medium_algorithm(stack_a, info);
 		else if (!ft_strcmp((*stack_a)->flag + 10, "O(nlogn)"))
			// complex
	} */
}
