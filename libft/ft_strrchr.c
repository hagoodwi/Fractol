/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:41:18 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/15 13:03:35 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lp;

	lp = NULL;
	while (*s)
	{
		if (*s == c)
			lp = (char*)s;
		++s;
	}
	if (lp)
		return (lp);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
