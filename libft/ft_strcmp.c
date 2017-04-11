/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:45:40 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/22 15:23:34 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	unsigned const char	*s1_temp;
	unsigned const char	*s2_temp;

	s1_temp = (unsigned const char*)s1;
	s2_temp = (unsigned const char*)s2;
	i = 0;
	while (s1_temp[i] && s2_temp[i])
	{
		if (s1_temp[i] != s2_temp[i])
			return (s1_temp[i] - s2_temp[i]);
		i++;
	}
	return (s1_temp[i] - s2_temp[i]);
}
