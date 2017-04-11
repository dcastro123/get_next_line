/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 21:06:41 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/25 13:36:02 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wdcount(char const *s, char c)
{
	size_t	num_words;
	int		i;

	i = 0;
	num_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			num_words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (num_words);
}
