/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:48:54 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/09/10 16:04:39 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*strc;
	int		i;

	i = 0;
	strc = (char*)malloc(sizeof(*strc) * (ft_strlen(str) + 1));
	if (strc == NULL)
		return (NULL);
	while (str[i])
	{
		strc[i] = str[i];
		i++;
	}
	strc[i] = '\0';
	return (strc);
}
