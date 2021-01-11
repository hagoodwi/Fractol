/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:49:06 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/10 16:36:07 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char *a;
	unsigned char b;

	b = (unsigned char)c;
	a = (unsigned char*)destination;
	while (n)
	{
		*a = b;
		a++;
		n--;
	}
	return (destination);
}
