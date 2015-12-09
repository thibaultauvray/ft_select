/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_vert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 17:54:32 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/23 13:42:34 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_move_pos(int pox, int posy)
{
	t_sel	*head;
	int		i;

	i = 0;
	head = g_elem.lst;
	while (g_elem.lst != NULL)
	{
		if (g_elem.lst->posx == pox && g_elem.lst->posy == posy)
		{
			i = 1;
			g_elem.lst->actif = 1;
		}
		if (g_elem.lst->next)
			g_elem.lst = g_elem.lst->next;
		else
			break ;
	}
	if (i == 0)
		g_elem.lst->actif = 1;
	g_elem.lst = head;
}

void			ft_move_up(int ww, int maxheight)
{
	t_sel	*head;
	int		i;
	int		wh;
	int		posx;
	int		posy;

	i = 1;
	head = g_elem.lst;
	while (g_elem.lst->actif == 0)
	{
		i++;
		g_elem.lst = g_elem.lst->next;
	}
	posx = g_elem.lst->posx;
	posy = g_elem.lst->posy;
	wh = ft_count_height(ww, maxheight);
	if (posy != 0)
		ft_pos(posx, posy - 1, head);
	else
		ft_pos(posx, wh - 1, head);
	g_elem.lst = head;
}

void			ft_move_down(int ww, int maxheight)
{
	t_sel	*head;
	int		i;
	int		posx;
	int		posy;
	int		wh;

	i = 1;
	head = g_elem.lst;
	while (g_elem.lst->actif == 0)
	{
		i++;
		g_elem.lst = g_elem.lst->next;
	}
	wh = ft_count_height(ww, maxheight);
	posx = g_elem.lst->posx;
	posy = g_elem.lst->posy;
	if (posy != wh - 1)
		ft_pos(posx, posy + 1, head);
	else
		ft_pos(posx, 0, head);
	g_elem.lst = head;
}
