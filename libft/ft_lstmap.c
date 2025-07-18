/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:59:26 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*static void	del(void *c)
{
	free(c);
}*/

/*static void	*f(void *c)
{
	char	*str;
	char	*newstr;
	char	*temp;

	str = (char *)c;
	newstr = ft_strdup(str);
	temp = newstr;
	if (!newstr)
		return (NULL);
	while (*temp)
	{
		if (*temp >= 'a' && *temp <= 'z')
			*temp -= 32;
		temp++;
	}
	return ((void *)newstr);
}*/

/*static void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*resf;

	newlist = NULL;
	newnode = NULL;
	resf = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		resf = f(lst->content);
		newnode = ft_lstnew(resf);
		if (!newnode)
		{
			del(resf);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}

/*int main()
{
	// cc -Wall -Werror -Wextra ft_lstmap.c ft_strdup.c ft_lstclear.c
	ft_lstiter.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c
	
	t_list *head = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("Nodo 1"));
	t_list *node2 = ft_lstnew(ft_strdup("Nodo 2"));
	t_list *node3 = ft_lstnew(ft_strdup("Nodo 3"));

	head = node1;
	node1->next = node2;
	node2->next = node3;

	printf("Contenuto lista prima del richiamo:\n");
	ft_lstiter(head, print_content);

	t_list *newlist = ft_lstmap(head, f, del);

	printf("Contenuto lista dopo il richiamo:\n");
	ft_lstiter(newlist, print_content);

	ft_lstclear(&head, del);
	ft_lstclear(&newlist, del);

	return 0;
}*/
