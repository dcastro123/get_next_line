/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:42:41 by dcastro-          #+#    #+#             */
/*   Updated: 2017/03/08 20:14:17 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_line(char **buf_keep, char *buff, char **line)
{
	char	*buff_temp;

	if ((buff_temp = ft_strchr(buff, '\n')))
	{
		*buff_temp = '\0';
		*line = ft_strjoin(*buf_keep, buff);
		free(*buf_keep);
		*buf_keep = ft_strdup(buff_temp);
		buff_temp = NULL;
		free(buff);
		return (1);
	}
	return (0);
}

static int	read_static_buff(char **buf_keep, char **line)
{
	char *temp;
	if (temp = ft_strchr(*buf_keep, '\n'))
	{
		*temp = '\0';
		*line = ft_strdup(*buf_keep);
		free(*buf_keep);
		*buf_keep = ft_strdup(*temp);
		temp = NULL;
		return (1);
	}
	return (0);
}
int		get_next_line(const int fd, char **line)
{
	static	char 	*buf_keep = NULL;
	char			buff[BUFF_SIZE];
	int				byte_count;

	if (!*line)
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	if (buf_keep != '\0')
	{
		if (read_static_buff(&buf_keep, line))
			return (1);
	}
	while ((byte_count = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[byte_count] = '\0';
		if (read_line(&buf_keep, buff, line))
			return (1);
		printf("printing static buff: %s\n", buf_keep); //REMOVE BEFORE SUBMITTING!!!!!!!!!!!!!!
		if (!(buf_keep = ft_strjoin(buf_keep, buff)))
			return (-1);
	}
	free (buff);
	buff = NULL;
	if (buf_keep == NULL)
		return (0);
	*line = buf_keep;
	free (buf_keep);
	buf_keep == NULL;
	return (1);
}
