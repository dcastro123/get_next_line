/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:04:56 by dcastro-          #+#    #+#             */
/*   Updated: 2017/02/11 21:05:44 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;
	size_t			i;

	s1_temp = (unsigned char*)s1;
	s2_temp = (unsigned char*)s2;
	i = 0;
	while (s1_temp[i] && i < n)
	{
		if (s1_temp[i] != s2_temp[i])
			return (s1_temp[i] - s2_temp[i]);
		i++;
	}
	if (n != 0 && i == n)
		return (s1_temp[i - 1] - s2_temp[i - 1]);
	if (n == 0)
		return (0);
	return (s1_temp[i] - s2_temp[i]);
}
