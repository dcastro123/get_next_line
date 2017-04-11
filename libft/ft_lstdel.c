/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:54:04 by dcastro-          #+#    #+#             */
/*   Updated: 2017/01/21 22:03:08 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*temp;

	if (!alst || !del)
		return ;
	node = *alst;
	while (node)
	{
		temp = node->next;
		del(node->content, node->content_size);
		free(node);
		node = temp;
	}
	*alst = NULL;
}
