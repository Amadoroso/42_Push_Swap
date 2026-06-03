/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:02 by apinho-a          #+#    #+#             */
/*   Updated: 2026/06/03 10:38:08 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// struct that holds the int, aswell as other info
typedef struct s_stack_node
{
	size_t				index;
	int					nbr;
	struct s_stack_node	*next;
}				t_stack_node;

void			ft_stack_clear(t_stack_node **stack_head);
t_stack_node	*ft_node_new(int index, int atoi_result);
void			ft_stack_add(t_stack_node *stack_head, t_stack_node *new_node);
int				ft_argv_parser(int argc, char **argv);

#endif