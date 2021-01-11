/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:12:44 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/20 13:39:44 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*str;

	if (s1 && s2)
		len = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2);
	else if (s1)
		len = (size_t)ft_strlen(s1);
	else if (s2)
		len = (size_t)ft_strlen(s2);
	else
		return (NULL);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (s1)
		str = ft_strcpy(str, s1);
	else
		str = ft_strcpy(str, s2);
	if (s1 && s2)
		str = ft_strcat(str, s2);
	return (str);
}
