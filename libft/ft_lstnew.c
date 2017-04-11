/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:30:10 by dcastro-          #+#    #+#             */
/*   Updated: 2017/02/21 16:35:16 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;
	void	*ccpy;

	node = (t_list*)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (node)
	{
		if (!content)
		{
			node->content = NULL;
			node->content_size = 0;
		}
		else
		{
			ccpy = (void*)malloc(content_size);
			ccpy = ft_memcpy(ccpy, content, content_size);
			node->content = ccpy;
			node->content_size = content_size;
		}
	}
	node->next = NULL;
	return (node);
}
