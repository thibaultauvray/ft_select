/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/09 14:36:38 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/23 13:28:20 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	*ft_init_buffer(char *read_char)
{
	read_char[0] = 0;
	read_char[1] = 0;
	read_char[2] = 0;
	read_char[3] = 0;
	return (read_char);
}

void	ft_quit_term(void)
{
	ft_resetterm();
	tputs(tgetstr("te", NULL), g_elem.fd, my_outc);
	exit(1);
}

void	ft_move(int ww, int maxheight)
{
	char	buffer[3];

	buffer[0] = 0;
	buffer[1] = 0;
	buffer[2] = 0;
	tputs(tgetstr("ks", NULL), g_elem.fd, my_outc);
	read(0, buffer, 3);
	tputs(tgetstr("ke", NULL), g_elem.fd, my_outc);
	ft_key(buffer, ww, maxheight);
}

void	ft_move_right(void)
{
	t_sel *head;

	head = g_elem.lst;
	while (g_elem.lst->actif == 0)
		g_elem.lst = g_elem.lst->next;
	g_elem.lst->actif = 0;
	if (g_elem.lst->next)
	{
		g_elem.lst->next->actif = 1;
	}
	else
	{
		g_elem.lst = head;
		g_elem.lst->actif = 1;
	}
	g_elem.lst = head;
}

void	ft_move_left(void)
{
	t_sel	*head;
	int		i;
	int		j;

	head = g_elem.lst;
	j = 0;
	i = 0;
	while (g_elem.lst->actif == 0)
	{
		i++;
		g_elem.lst = g_elem.lst->next;
	}
	if (i == 0)
	{
		g_elem.lst = head;
		ft_move_left_spe();
	}
	else
	{
		ft_move_left_spe2(i, j, head);
	}
}
