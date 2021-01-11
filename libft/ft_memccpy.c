/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:56:40 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/10 16:57:24 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	int				i;
	unsigned char	*dst;
	unsigned char	*src;
	unsigned char	b;

	i = 0;
	if (dest == source)
		return (dest);
	b = (unsigned char)c;
	dst = (unsigned char*)dest;
	src = (unsigned char*)source;
	while (n)
	{
		dst[i] = src[i];
		if (src[i] == b)
			return (dst + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
