/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:03 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/17 14:39:57 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest_temp;
	char	*src_temp;
	size_t	i;

	dest_temp = (char *)dst;
	src_temp = (char *)src;
	i = 0;
	while (i < n)
	{
		dest_temp[i] = src_temp[i];
		i++;
	}
	return (dst);
}
