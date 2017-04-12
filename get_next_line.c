/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:42:41 by dcastro-          #+#    #+#             */
/*   Updated: 2017/04/11 16:42:00 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		send_help(char **buf_keep, char **line)
{
	char	*temp;
	size_t	len;

	len = ft_wdlen(*buf_keep, '\n');
	if (ft_strlen(*buf_keep))
	{
		if (ft_strchr(*buf_keep, '\n'))
		{
			*line = ft_strsub(*buf_keep, 0, len);
//			temp = ft_strdup(*buf_keep + len + 1);
			temp = ft_strsub(*buf_keep, (len + 1),
					(ft_strlen(*buf_keep) - (len + 1)));
			free(*buf_keep);
			*buf_keep = temp;
			return (1);
		}
		*line = ft_strdup(*buf_keep);
		free(*buf_keep);
		*buf_keep = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*buf_keep;
	char			buff[BUFF_SIZE + 1];
	int				byte_count;
	char 			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	while ((byte_count = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[byte_count] = '\0';
		if (!buf_keep)
			buf_keep = ft_strnew(1);
		tmp = ft_strjoin(buf_keep, buff);
		free(buf_keep);
		buf_keep = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (send_help(&buf_keep, line))
		return (1);
	return (0);
}