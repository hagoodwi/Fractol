/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:40:20 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/20 20:29:14 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		nb_b(char const *s)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
	{
		if ((len - 1) == 0)
			return (0);
		len--;
	}
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		len--;
		i++;
	}
	if (len <= 0)
		return (0);
	return (len);
}

char					*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	len = nb_b(s);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}
