/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:45:25 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/20 18:48:56 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				res;
	int				sign;
	unsigned char	*s;

	i = 0;
	res = 0;
	sign = 1;
	s = (unsigned char*)str;
	while (ft_spacecheck(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = ((res * 10) + s[i] - '0');
		i++;
	}
	return (sign * res);
}
