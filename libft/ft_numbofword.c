/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numboflet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:38:26 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/20 21:53:16 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_numbofword(char const *s, char c)
{
	unsigned int k;

	k = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			k++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (k);
}
