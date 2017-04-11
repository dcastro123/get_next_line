/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:46:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/25 15:35:55 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**temp;

	if (!s || !c)
		return (NULL);
	if (!(temp = (char **)malloc(sizeof(char*) * (ft_wdcount(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			if (!(temp[i] = (char*)malloc(sizeof(char) * (ft_wdlen(s, c) + 1))))
				return (NULL);
			while (ft_wdlen(s, c) > 0)
				temp[i][j++] = *s++;
			temp[i++][j] = '\0';
		}
		else
			s++;
	}
	temp[i] = 0;
	return (temp);
}
