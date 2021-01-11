/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:57:43 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/21 20:05:38 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (dest == source)
		return (dest);
	ptr = (unsigned char*)dest;
	ptr2 = (unsigned char*)source;
	i = 0;
	if (ptr2 < ptr)
		while (++i <= n)
			ptr[n - i] = ptr2[n - i];
	else
		while (n-- > 0)
			*(ptr++) = *(ptr2++);
	return (dest);
}
