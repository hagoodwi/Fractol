/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:39:54 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/15 16:31:38 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*ar1;
	unsigned char	*ar2;

	if (n == 0 || arr1 == arr2)
		return (0);
	ar1 = (unsigned char*)arr1;
	ar2 = (unsigned char*)arr2;
	i = 0;
	while (*ar1 == *ar2 && i < (n - 1))
	{
		ar1++;
		ar2++;
		i++;
	}
	return ((int)(*ar1 - *ar2));
}
