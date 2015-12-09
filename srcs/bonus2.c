/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:42:54 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/27 17:48:13 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_key2(char *buffer)
{
	if (IKEY)
		ft_reverse();
	if (RKEY)
		ft_undo();
	if (AKEY)
		ft_trial();
	if (QKEY)
		ft_trialreverse();
	if (HOME)
		ft_home();
	if (END)
		ft_end();
}

static char		*ft_strtolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

static t_tri	ft_swaptri(t_tri l)
{
	l.col_tmp = l.p->col;
	l.actif = l.p->select;
	l.tmp = l.p->content;
	l.ds = l.p->content_size;
	l.p->content = l.min->content;
	l.p->col = l.min->col;
	l.p->content_size = l.min->content_size;
	l.p->select = l.min->select;
	l.min->content = l.tmp;
	l.min->col = l.col_tmp;
	l.min->select = l.actif;
	l.min->content_size = l.ds;
	return (l);
}

void			ft_trial(void)
{
	t_tri	l;

	l.head = g_elem.lst;
	l.p = l.head;
	while (l.p->next != NULL)
	{
		l.min = l.p;
		l.q = l.p->next;
		while (l.q)
		{
			l.tmp1 = ft_strdup(l.q->content);
			l.tmp2 = ft_strdup(l.min->content);
			if (ft_strcmp(ft_strtolower(l.tmp1), ft_strtolower(l.tmp2)) < 0)
				l.min = l.q;
			free(l.tmp1);
			free(l.tmp2);
			l.q = l.q->next;
		}
		l = ft_swaptri(l);
		l.p = l.p->next;
	}
	g_elem.lst = l.head;
}

void			ft_trialreverse(void)
{
	t_tri	l;

	l.head = g_elem.lst;
	l.p = l.head;
	while (l.p->next != NULL)
	{
		l.min = l.p;
		l.q = l.p->next;
		while (l.q)
		{
			l.tmp1 = ft_strdup(l.q->content);
			l.tmp2 = ft_strdup(l.min->content);
			if (ft_strcmp(ft_strtolower(l.tmp1), ft_strtolower(l.tmp2)) > 0)
				l.min = l.q;
			free(l.tmp1);
			free(l.tmp2);
			l.q = l.q->next;
		}
		l = ft_swaptri(l);
		l.p = l.p->next;
	}
	g_elem.lst = l.head;
}
