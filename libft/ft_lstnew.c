/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 21:04:14 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/23 21:04:15 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node)
	{
		if (content == NULL)
		{
			new_node->content = NULL;
			new_node->content_size = 0;
			return (new_node);
		}
		new_node->content = malloc(content_size);
		ft_memcpy(new_node->content, content, content_size);
		new_node->content_size = content_size;
	}
	return (new_node);
}
