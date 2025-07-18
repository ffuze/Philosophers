/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:31:28 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = NULL;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

/* int main()
{
	t_list *head = NULL;

	t_list *node1 = ft_lstnew("Nodo 1");
	t_list *node2 = ft_lstnew("Nodo 2");
	t_list *node3 = ft_lstnew("Nodo 3");
	t_list *alonenode = ft_lstnew("im alone :(");

	node1->next = node2;
	node2->next = node3;

	head = node1;

	printf("Lista prima del richiamo:\n");
	int i = 1;
	t_list *temp = head;
	while (temp){
		printf("Contenuto %d: %s\n", i, (char *)temp->content);
		temp = temp->next;
		i++;
	}

	ft_lstadd_back(&head, alonenode);
	
	printf("Lista dopo il richiamo:\n");
	i = 1;
	temp = head;
	while (temp){
		printf("Contenuto %d: %s\n", i, (char *)temp->content);
		temp = temp->next;
		i++;
	}
} */
