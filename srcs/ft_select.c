/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 14:40:00 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/28 11:56:23 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			do_op(int w)
{
	struct winsize ws;

	if (w == SIGWINCH)
	{
		ioctl(0, TIOCGWINSZ, &ws);
		g_elem.maxwidth = ws.ws_col;
		g_elem.maxheight = ws.ws_row;
		ft_show(g_elem.maxwidth, g_elem.maxheight,
				ft_count_line(g_elem.maxwidth));
	}
	if (w == SIGINT || w == SIGQUIT || w == SIGABRT || w == SIGKILL
			|| w == SIGTERM || w == SIGSEGV || w == SIGBUS)
	{
		ft_quit_term();
	}
}

void			ft_select(void)
{
	struct winsize	ws;
	int				i;

	ioctl(0, TIOCGWINSZ, &ws);
	g_elem.maxwidth = ws.ws_col;
	g_elem.maxheight = ws.ws_row;
	while (1)
	{
		i = ft_count_line(g_elem.maxwidth);
		ft_show(g_elem.maxwidth, g_elem.maxheight,
				i);
		ft_move(i, g_elem.maxheight);
	}
}

static void		ft_under(int o, int x, int y)
{
	if (o == 1)
	{
		if (g_elem.lst->col == 4)
			ft_putstr_fd("\033[5;31;m", g_elem.fd);
		if (g_elem.lst->col == 3)
			ft_putstr_fd("\033[34;01;m", g_elem.fd);
		if (g_elem.lst->col == 2)
			ft_putstr_fd("\033[34;m", g_elem.fd);
		if (g_elem.lst->col == 1)
			ft_putstr_fd("\033[33;m", g_elem.fd);
		if (g_elem.lst->actif == 1)
			tputs(tgetstr("mr", NULL), g_elem.fd, my_outc);
		if (g_elem.lst->select == 1)
			tputs(tgetstr("us", NULL), 1, my_outc);
		tputs(tgoto((tgetstr("cm", NULL)), x, y), g_elem.fd, my_outc);
	}
	else
	{
		if (g_elem.lst->actif == 1)
			tputs(tgetstr("me", NULL), g_elem.fd, my_outc);
		if (g_elem.lst->select == 1)
			tputs(tgetstr("ue", NULL), g_elem.fd, my_outc);
		if (g_elem.lst->col != 0)
			ft_putstr_fd("\033[m", g_elem.fd);
	}
}

static t_show	ft_select_if(t_show m, int ww)
{
	m.x = m.x + m.margex;
	g_elem.lst->posx = m.nbx;
	g_elem.lst->posy = m.nby;
	g_elem.lst = g_elem.lst->next;
	m.nbx++;
	if (m.nbx == ww)
	{
		m.y = m.y + MARGINY;
		m.nby++;
		m.x = MARGIN;
		m.nbx = 0;
	}
	return (m);
}

void			ft_show(int maxwidth, int maxheight, int ww)
{
	t_show	m;
	t_sel	*head;

	tputs(tgetstr("cl", NULL), g_elem.fd, my_outc);
	if (ft_count_height(ww, maxheight) == -1 || ft_small(ww, maxwidth) == -1)
		ft_show_too_small();
	else
	{
		m.nbx = 0;
		m.nby = 0;
		m.x = MARGIN;
		head = g_elem.lst;
		m.y = MARGINY;
		m.margex = ((maxwidth - (MARGIN)) / ww);
		while (g_elem.lst != NULL)
		{
			ft_under(1, m.x, m.y);
			write(g_elem.fd, g_elem.lst->content, g_elem.lst->content_size);
			ft_under(0, m.x, m.y);
			m = ft_select_if(m, ww);
		}
		g_elem.lst = head;
	}
}
