/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 17:21:34 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/24 14:36:36 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_count_list(void)
{
	t_sel	*head;
	int		i;

	i = 0;
	head = g_elem.lst;
	while (g_elem.lst)
	{
		i++;
		g_elem.lst = g_elem.lst->next;
	}
	g_elem.lst = head;
	return (i);
}

void	ft_del(void)
{
	t_sel	*courant;
	t_sel	*supp_element;

	supp_element = NULL;
	if (ft_count_list() == 1)
		ft_quit_term();
	g_elem.nbrelem = g_elem.nbrelem - 1;
	courant = g_elem.lst;
	if (g_elem.lst->actif == 1)
		ft_del_first(supp_element);
	else
		ft_del2(courant, supp_element);
}

void	ft_selection(void)
{
	t_sel *head;

	head = g_elem.lst;
	while (g_elem.lst->actif == 0)
	{
		g_elem.lst = g_elem.lst->next;
	}
	if (g_elem.lst->select == 0)
		g_elem.lst->select = 1;
	else
		g_elem.lst->select = 0;
	g_elem.lst = head;
	ft_move_right();
}

int		my_outc(int c)
{
	write(g_elem.fd, &c, 1);
	return (1);
}

int		ft_count_height(int ww, int maxheight)
{
	int	i;
	int	j;
	int	max;

	j = 1;
	max = MARGINY;
	i = 0;
	while ((ww * j) < g_elem.nbrelem)
	{
		max = max + MARGINY;
		if (max > maxheight)
		{
			return (-1);
		}
		j++;
	}
	if (max > maxheight)
	{
		return (-1);
	}
	return (j);
}
