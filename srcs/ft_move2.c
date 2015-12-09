/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 16:00:22 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/23 13:48:59 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_key(char *buffer, int ww, int maxheight)
{
	if (UP)
		ft_move_up(ww, maxheight);
	if (DOWN)
		ft_move_down(ww, maxheight);
	if (RIGHT)
		ft_move_right();
	if (LEFT)
		ft_move_left();
	if (SPACE)
		ft_selection();
	if (SUPPR)
		ft_del();
	if (ENTER)
		ft_return_values();
	if (CTRLD)
		ft_quit_term();
	if (ECHAP)
		ft_quit_term();
	ft_key2(buffer);
}

void		ft_move_left_spe2(int i, int j, t_sel *head)
{
	g_elem.lst->actif = 0;
	g_elem.lst = head;
	while (j != i - 1)
	{
		g_elem.lst = g_elem.lst->next;
		j++;
	}
	g_elem.lst->actif = 1;
	g_elem.lst = head;
}

void		ft_move_left_spe(void)
{
	t_sel	*head;

	head = g_elem.lst;
	g_elem.lst->actif = 0;
	while (g_elem.lst->next != NULL)
	{
		g_elem.lst = g_elem.lst->next;
	}
	g_elem.lst->actif = 1;
	g_elem.lst = head;
}

void		ft_pos(int x, int y, t_sel *head)
{
	g_elem.lst->actif = 0;
	g_elem.lst = head;
	ft_move_pos(x, y);
}

void		ft_del_first(t_sel *supp_element)
{
	supp_element = g_elem.lst;
	g_elem.lst = g_elem.lst->next;
	g_elem.lst->actif = 1;
	free(supp_element);
}
