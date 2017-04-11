/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:26:29 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/20 20:28:17 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_temp;
	unsigned char const	*src_temp;
	size_t				i;

	dst_temp = (unsigned char *)dst;
	src_temp = (unsigned char const *)src;
	if (dst_temp <= src_temp)
	{
		i = 0;
		while (len-- > 0)
		{
			dst_temp[i] = src_temp[i];
			i++;
		}
	}
	else
	{
		dst_temp = dst_temp + len - 1;
		src_temp = src_temp + len - 1;
		while (len-- > 0)
			*dst_temp-- = *src_temp--;
	}
	return (dst);
}
