/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:15:32 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/06 13:50:07 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
int	main ()
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *ptr;

	node1 = ft_lstnew("1");
	node2 = ft_lstnew("2");
	node3 = ft_lstnew("3");

	ptr = node1;
	printf("%s\n", (char *) ptr->content);
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	ptr = ft_lstlast(ptr);
	printf("%s\n", (char *) ptr->content);
} */