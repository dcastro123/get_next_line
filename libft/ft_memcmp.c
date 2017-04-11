/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:00:29 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/22 16:44:10 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1_temp;
	unsigned const char	*s2_temp;
	size_t				c;

	s1_temp = (unsigned const char *)s1;
	s2_temp = (unsigned const char *)s2;
	c = 0;
	while (c < n)
	{
		if (s1_temp[c] != s2_temp[c])
			return (s1_temp[c] - s2_temp[c]);
		c++;
	}
	return (0);
}
