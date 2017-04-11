/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:00:43 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/20 23:29:14 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while ((nbr / 10) != 0)
	{
		i++;
		nbr /= 10;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = num_len(n) - 1;
	if (!(str = (char *)malloc(sizeof(char) * (num_len(n) + 1))))
		return (NULL);
	str[i + 1] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		str[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	if (n >= 0 && n <= 9)
		str[i] = n + '0';
	return (str);
}
