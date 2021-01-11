/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:40:30 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/10 17:26:44 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	int				i;
	unsigned char	*prt;

	i = 0;
	prt = (unsigned char*)arr;
	while (n)
	{
		if (prt[i] == (unsigned char)c)
			return (prt + i);
		i++;
		n--;
	}
	return (NULL);
}
