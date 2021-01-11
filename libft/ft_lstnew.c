/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:10:51 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/21 17:57:21 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*prt;

	if ((prt = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		prt->content = NULL;
		prt->content_size = 0;
	}
	else
	{
		if ((prt->content = malloc(content_size)) == NULL)
		{
			free(prt);
			return (NULL);
		}
		prt->content = ft_memcpy(prt->content, content, content_size);
		prt->content_size = content_size;
	}
	prt->next = NULL;
	return (prt);
}
