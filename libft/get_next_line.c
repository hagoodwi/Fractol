/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:12:32 by hagoodwi          #+#    #+#             */
/*   Updated: 2019/11/18 21:14:37 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		not_end(char **str, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*str)[i] != '\n')
		i++;
	*line = ft_strsub(*str, 0, i);
	(*line)[i] = '\0';
	tmp = ft_strsub(*str, i + 1, ft_strlen(*str) - i - 1);
	free(*str);
	*str = tmp;
	return (1);
}

int		end(char **str, char **line, int res)
{
	char	*tmp;

	if (res == 0 && ft_strlen(*str))
	{
		*line = ft_strsub(*str, 0, ft_strlen(*str));
		tmp = ft_strsub(*str, ft_strlen(*str), 0);
		free(*str);
		*str = tmp;
		return (1);
	}
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[10241];
	char		*buf;
	char		*tmp;
	int			res;

	if (fd < 0 || !line || BUFF_SIZE < 0 || fd > 10240)
		return (-1);
	buf = ft_strnew(BUFF_SIZE + 1);
	if (!str[fd])
		str[fd] = ft_strnew(BUFF_SIZE);
	if (!buf || !str[fd])
		return (-1);
	while (!ft_strchr(str[fd], '\n') && (res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	if (ft_strchr(str[fd], '\n'))
		return (not_end(&str[fd], line));
	return (end(&str[fd], line, res));
}
