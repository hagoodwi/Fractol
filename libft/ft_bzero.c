/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:54:13 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/10 13:52:14 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *a;

	a = (unsigned char*)s;
	while (n)
	{
		*a = 0;
		a++;
		n--;
	}
}
