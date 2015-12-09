/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaire3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 13:44:11 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/23 13:48:10 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_findmax(t_sel *head)
{
	size_t		max;

	max = 0;
	while (g_elem.lst)
	{
		if (g_elem.lst->content_size > max)
			max = g_elem.lst->content_size;
		g_elem.lst = g_elem.lst->next;
	}
	max = max + MARGIN;
	g_elem.lst = head;
	return (max);
}
