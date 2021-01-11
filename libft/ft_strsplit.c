/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:32:41 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/21 13:48:01 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int					i;
	unsigned int		lett;
	char				**str;

	if (!s || !c)
		return (NULL);
	i = (int)ft_numbofword(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	str[i] = NULL;
	i = 0;
	while (1)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (str);
		lett = ft_numboflet(s, c);
		if (!(str[i] = (char*)malloc(sizeof(char) * (lett + 1))))
			return (ft_arfree(&str));
		str[i] = ft_strncpy(str[i], s, lett);
		str[i++][lett] = '\0';
		s += lett;
	}
	return (str);
}
