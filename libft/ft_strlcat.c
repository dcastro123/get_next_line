/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:39:59 by dcastro-          #+#    #+#             */
/*   Updated: 2017/02/11 19:33:24 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_temp;
	const char	*src_temp;
	size_t		dst_len;
	size_t		j;
	size_t		k;

	dst_temp = dst;
	src_temp = src;
	j = size;
	while (j-- > 0 && *dst_temp != '\0')
		dst_temp++;
	dst_len = dst_temp - dst;
	k = dst_len + ft_strlen(src);
	j = size - dst_len;
	if (j <= 0)
		return (dst_len + ft_strlen(src_temp));
	while (*src_temp != '\0' && j > 1)
	{
		*dst_temp++ = *src_temp++;
		j--;
	}
	*dst_temp = '\0';
	return (k);
}
