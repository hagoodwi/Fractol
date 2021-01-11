/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:30:24 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/21 15:38:47 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi(const char *s)
{
	long long	res;
	long long	prov;
	int			flag;

	res = 0;
	prov = 0;
	flag = 1;
	while ((*s == ' ' || *s == '\n' || *s == '\t' || *s == '\r' ||
			*s == '\v' || *s == '\f') && *s)
		s++;
	if (*s == '-')
		flag = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		prov = res;
		res = res * 10 + (*s - '0');
		if (prov != res / 10)
			return (flag > 0 ? -1 : 0);
		s++;
	}
	res = res * (long long)flag;
	return (res);
}
