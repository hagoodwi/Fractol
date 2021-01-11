/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:25:43 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/21 19:04:35 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		list_free(t_list *prt)
{
	t_list		*prt1;

	while (prt)
	{
		prt1 = prt->next;
		if (prt->content)
			free(prt->content);
		free(prt);
		prt = prt1;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*prt;
	t_list		*head;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((head = (*f)(lst)) == NULL)
		return (NULL);
	prt = head;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((prt->next = (*f)(lst)) == NULL)
		{
			list_free(head);
			return (NULL);
		}
		prt = prt->next;
		lst = lst->next;
	}
	return (head);
}
