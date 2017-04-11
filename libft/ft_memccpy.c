/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 10:37:02 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/24 21:41:31 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dst_temp;
	unsigned const char		*src_temp;
	size_t					i;

	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned const char *)src;
	i = 0;
	if (i == n)
		return (NULL);
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		if (src_temp[i] == (unsigned char)c)
		{
			i++;
			return (&dst_temp[i]);
		}
		i++;
	}
	return (NULL);
}
