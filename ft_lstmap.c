/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthewara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 02:14:23 by bthewara          #+#    #+#             */
/*   Updated: 2022/06/13 13:14:03 by bthewara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;

	if (!lst)
		return (NULL);
	else
	{
		map = ft_lstnew(f(lst->content));
		if (!map)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		map->next = ft_lstmap(lst->next, f, del);
		return (map);
	}
}
