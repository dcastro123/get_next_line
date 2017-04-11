/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 20:12:26 by dcastro-          #+#    #+#             */
/*   Updated: 2017/02/18 00:36:49 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		node = f(lst);
		node->next = ft_lstmap(lst->next, f);
		return (node);
	}
	return (NULL);
}
