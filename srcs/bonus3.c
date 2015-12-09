/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 17:04:08 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/27 17:48:01 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_home(void)
{
	t_sel	*head;

	head = g_elem.lst;
	while (g_elem.lst)
	{
		g_elem.lst->actif = 0;
		g_elem.lst = g_elem.lst->next;
	}
	g_elem.lst = head;
	g_elem.lst->actif = 1;
}

void		ft_end(void)
{
	t_sel	*head;

	head = g_elem.lst;
	while (g_elem.lst)
	{
		g_elem.lst->actif = 0;
		if (!g_elem.lst->next)
		{
			g_elem.lst->actif = 1;
		}
		g_elem.lst = g_elem.lst->next;
	}
	g_elem.lst = head;
}
