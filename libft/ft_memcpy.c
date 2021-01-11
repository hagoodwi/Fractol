/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:55:36 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/10 16:54:04 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;
	int				i;

	dst = (unsigned char*)dest;
	src = (unsigned char*)source;
	if (dest == source)
		return (dest);
	i = 0;
	while (n)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	return (dest);
}
