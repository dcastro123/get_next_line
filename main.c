/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:09:51 by dcastro-          #+#    #+#             */
/*   Updated: 2017/04/11 18:54:35 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		res;
	int		num;

	res = 0;
	num = 0;
	line = NULL;
	argc = 0;
	fd = open(argv[1], O_RDONLY);
	
	if (fd > 0)
		while ((res = get_next_line(fd, &line)) > 0)
		{
			printf("[Ret: %d, # of Line: %d, FD: %d] %s\n", res, ++num, fd, line);
			ft_strdel(&line);
		}
	ft_strdel(&line);
	printf("[Ret: %d, # of Line: %d, FD: %d] %s\n", res, ++num, fd, line);
	if ((fd > 0 && (close(fd) == -1 || res != 0)) || fd < 0)
	{
		if (!line)
			write(1, "error\n", 6);
		return (1);
	}
	printf ("/* Ret == 1 ; read line\n   Ret == 0 ; end of line(finish) */\n");
	return (0);
}