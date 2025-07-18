/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:20:38 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*void	del(void *c)
{
	free(c);
}*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
}

/*int main()
{
	t_list *head = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("Nodo 1"));
	t_list *node2 = ft_lstnew(ft_strdup("Nodo 2"));
	t_list *node3 = ft_lstnew(ft_strdup("Nodo 3"));
    
	head = node1;

	node1->next = node2;
	node2->next = node3;

	t_list *temp = head;
	int i = 1;
	printf("Stampo la lista: \n");
	while (temp){
		printf("Contenuto %d: %s\n", i, (char *)temp->content);
		temp = temp->next;
		i++;
	}

    ft_lstclear(&head, del);

	if (!head)
    	printf("Lista eliminata con successo");
	else
		printf("Ha coglione non funziona\n");

    return 0;
}*/
