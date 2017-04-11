/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:18:29 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/30 00:56:25 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*big_temp;
	const char	*little_temp;
	const char	*i;

	if (*little == '\0')
		return ((char*)big);
	i = big + len;
	while (*big && big <= i)
	{
		big_temp = big;
		little_temp = little;
		while (*big_temp && (big_temp < i) && *little_temp)
		{
			if (*big_temp++ == *little_temp)
				little_temp++;
			else
				break ;
		}
		if (*little_temp == 0)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
