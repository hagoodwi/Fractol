/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:28:11 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/20 15:23:05 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		while (*s)
		{
			*str = (*f)(*s);
			str++;
			s++;
		}
		*str = '\0';
		return (str - len);
	}
	return (NULL);
}
