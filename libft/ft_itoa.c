/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:15:18 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/21 15:59:36 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		am_nb(unsigned int n)
{
	int i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				i;

	i = 0;
	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	i = am_nb(nb) + (n < 0 ? 1 : 0);
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[i--] = '\0';
	while (nb >= 10)
	{
		str[i--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[i] = (char)(nb % 10 + 48);
	return (str);
}
