/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:39:26 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/15 13:54:41 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (*str2 == '\0')
		return ((char*)str1);
	while (str1[i] && (size_t)i < len)
	{
		if (str1[i] == str2[j])
		{
			while (str1[i + j] == str2[j] && str2[j] && (size_t)(i + j) < len)
				j++;
			if (!str2[j])
				return ((char*)(str1 + i));
			j = 0;
		}
		i++;
	}
	return (NULL);
}
