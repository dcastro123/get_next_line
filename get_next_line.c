/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:42:41 by dcastro-          #+#    #+#             */
/*   Updated: 2017/04/11 01:10:58 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*
static	int		read_onto_buf(char *buf_keep, char **line)
{
	size_t len;
	char *temp;

	temp = buf_keep;
	len = ft_wdlen(buf_keep, '\n');
	if (ft_strchr(buf_keep, '\n'))
	{
//		printf("found new line\n");
		*line = ft_strsub(temp, 0, len);
		buf_keep = ft_strsub(temp, (len + 1),
				(ft_strlen(temp) - (len + 1)));
		free(temp);
		temp = NULL;
		return (1);
	}
	if (ft_strlen(buf_keep))
	{
//		printf("no new line\n");
		*line = ft_strdup(buf_keep);
		free(buf_keep);
		buf_keep = NULL;
		return (1);
	}
//	printf("no nl found-----------------------");
	return (0);
}
*/
int		send_help(char **buf_keep, char **line)
{
	char 	*temp;
	size_t	len;

	len = ft_wdlen(*buf_keep, '\n');
	temp = *buf_keep;
	if (ft_strlen(*buf_keep))
	{
		if (ft_strchr(temp, '\n'))
		{
			*line = ft_strsub(temp, 0, len);
			*buf_keep = ft_strsub(temp, (len + 1), (ft_strlen(temp) - (len + 1)));
			free(temp);
			temp = NULL;
			return (1);
		}
		*line = ft_strdup(*buf_keep);
		free(buf_keep);
		buf_keep = NULL;
		return (1);
	}
	return (0);
}
int				get_next_line(const int fd, char **line)
{
	static	char	*buf_keep;
	char			buff[BUFF_SIZE];
	int				byte_count;
//	size_t			len;
//	char			*temp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	while ((byte_count = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[byte_count] = '\0';
		if (!buf_keep)
			buf_keep = ft_strnew(1);
		buf_keep = ft_strjoin(buf_keep, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	// len = ft_wdlen(buf_keep, '\n');
	if (send_help(&buf_keep, line))
		return (1);
	/*
	if (ft_strlen(buf_keep))
	{
		if (ft_strchr(buf_keep, '\n'))
		{
			temp = buf_keep;
			*line = ft_strsub(temp, 0, len);
			buf_keep = ft_strsub(temp, (len + 1),
				(ft_strlen(temp) - (len + 1)));
			free(temp);
			temp = NULL;
			return (1);
		}
		*line = ft_strdup(buf_keep);
		free(buf_keep);
		buf_keep = NULL;
		return (1);
	}
	*/
	return (0);
}