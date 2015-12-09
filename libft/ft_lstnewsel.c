/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:07:42 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/19 15:35:58 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sel			*ft_lstnewsel(void const *content, size_t content_size, int i)
{
	t_sel		*liste;

	liste = (t_sel *)malloc(sizeof(t_sel));
	if (liste)
	{
		if (content)
		{
			liste->content = malloc(sizeof(content) * content_size);
			liste->content = ft_memcpy(liste->content, content, content_size);
			liste->content_size = content_size;
			liste->actif = 0;
			liste->col = i;
		}
		else
		{
			liste->content = NULL;
			liste->content_size = 0;
		}
		liste->next = NULL;
	}
	return (liste);
}
