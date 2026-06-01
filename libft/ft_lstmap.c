/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:43:28 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/10 20:44:06 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* static void	*ft_capitalize(void *content)
{
	size_t	len;
	size_t	i;
	char	*new_content;
	char	*char_content;

	char_content = (char *) content;
	len = ft_strlen((char *) content);
	new_content = malloc (sizeof(char)*(len + 1));
	if (!new_content)
		return(NULL);
	i = 0;
	while (*(char_content + i) != 0)
	{
		if (*(char_content + i) >= 'a' && *(char_content + i) <= 'z')
			*(new_content + i) = *(char_content + i) - 32;
		else
			*(new_content + i) = *(char_content + i);
		i++;
	}
	*(new_content + i) = 0;
	return ((void *) new_content);
} */
/* static	void ft_del(void *content)
{
	free(content);
} */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	node = NULL;
	new_lst = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		node = ft_lstnew(new_content);
		if (node == NULL)
		{
			if (new_content != NULL)
				del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

/* int main()
{
	t_list	*ptr_node1;
	t_list	*ptr_node2;
	t_list	*ptr_node3;
	t_list	*lst_head;
	t_list	*new_lst_head;
	char	*content;
	
	content = ft_strdup("node1");
	if (!content)
		free(content); // leak prevention for ft_strdup failure
	ptr_node1 = ft_lstnew(content);
	if (!ptr_node1)  // they are seperated to prevent both leaks;
		free(ptr_node1); // leak prevention for ft_lstnew failure
	content = ft_strdup("node2");
	if (!content)
		free(content);
	ptr_node2 = ft_lstnew(content);
	if (!ptr_node2)
		free(ptr_node1);
	content = ft_strdup("node3");
	if (!content)
		free(content);
	ptr_node3 = ft_lstnew(content);
	if (!ptr_node3)
		free(ptr_node1);

	lst_head = ptr_node1;
	ft_lstadd_back(&lst_head, ptr_node2);
	ft_lstadd_back(&lst_head, ptr_node3); // lst of nodes is done

	new_lst_head = ft_lstmap(lst_head, ft_capitalize, ft_del);

	while (lst_head != NULL)
	{
		printf("%s\n", (char *) lst_head->content);
		lst_head = lst_head->next;
	}
	while (new_lst_head != NULL)
	{
		printf("%s\n", (char *) new_lst_head->content);
		new_lst_head = new_lst_head->next;
	}
	return (0);
} */