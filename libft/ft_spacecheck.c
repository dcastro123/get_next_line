/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacecheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:43:23 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/20 18:50:37 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_spacecheck(int c)
{
	unsigned char str;

	str = (unsigned char)c;
	if (str == ' ' || str == '\t' || str == '\r' || str == '\f' || str == '\n'
			|| str == '\v')
	{
		return (1);
	}
	return (0);
}
