/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:43:04 by dcastro-          #+#    #+#             */
/*   Updated: 2017/02/11 19:02:01 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*temp;
	size_t			i;
	size_t			j;
	size_t			len;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	if (i == ft_strlen(s))
		return (ft_strnew(1));
	j = ft_strlen(s) - 1;
	while (s[j] == '\t' || s[j] == ' ' || s[j] == '\n')
		j--;
	len = (j - i) + 1;
	if (!(temp = ft_strnew(len)))
		return (NULL);
	j = 0;
	while (len-- > 0)
		temp[j++] = s[i++];
	temp[j] = '\0';
	return (temp);
}
