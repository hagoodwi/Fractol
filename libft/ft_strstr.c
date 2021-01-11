/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:07:02 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/15 13:42:48 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (*str2 == '\0')
		return ((char*)str1);
	while (str1[i])
	{
		if (str1[i] == str2[j])
		{
			while (str1[i + j] == str2[j] && str1[i + j] && str2[j])
				j++;
			if (!str2[j])
				return ((char*)(str1 + i));
			j = 0;
		}
		i++;
	}
	return (NULL);
}
