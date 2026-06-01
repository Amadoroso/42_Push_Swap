/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:37:50 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/08 15:24:36 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int	main ()
{
	t_list *old;
	t_list *new;
	t_list **lst;

	old = ft_lstnew("goodbye");
	lst = &old;
	printf("%s\n", (char *) (*(lst + 0))->content);
	new = ft_lstnew("hello");
	ft_lstadd_front(lst, new);
	
	printf("%s\n", (char *) (*(lst + 0))->content);
	return (0);
} */