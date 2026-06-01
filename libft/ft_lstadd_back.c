/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:34:12 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/08 15:24:34 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*traveler;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	traveler = *lst;
	while (traveler->next != NULL)
		traveler = traveler->next;
	traveler->next = new;
}

/*
int	main()
{
	t_list	*ptr_node1;
	t_list	*ptr_node2;
	t_list	*ptr_node3;
	t_list *lst;
	t_list *ptr_lst;

	ptr_node1 = ft_lstnew("content1");
	ptr_node2 = ft_lstnew("content2");
	ptr_node3 = ft_lstnew("content3");
	
	lst = ptr_node1;
	ft_lstadd_back(&lst, ptr_node2);
	ft_lstadd_back(&lst, ptr_node3);

	ptr_lst = lst;
	while (ptr_lst->next != NULL)
	{
		printf("%s\n", (char *) ptr_lst->content);
		ptr_lst = ptr_lst->next;
	}
	printf("%s\n", (char *) ptr_lst->content);
	return (0);
} */