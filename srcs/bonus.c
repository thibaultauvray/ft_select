/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 13:54:03 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/21 16:09:07 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_reverse(void)
{
	t_sel	*head;

	head = g_elem.lst;
	while (g_elem.lst)
	{
		if (g_elem.lst->select == 1)
			g_elem.lst->select = 0;
		else if (g_elem.lst->select == 0)
			g_elem.lst->select = 1;
		g_elem.lst = g_elem.lst->next;
	}
	g_elem.lst = head;
}

void			ft_undo(void)
{
	t_sel	*head;

	head = g_elem.lst;
	while (g_elem.lst)
	{
		if (g_elem.lst->select == 1)
			g_elem.lst->select = 0;
		g_elem.lst = g_elem.lst->next;
	}
	g_elem.lst = head;
}

static char		*ft_find(char *av, t_bonus n)
{
	if (n.bol == 1)
	{
		if (!(n.ex = (char *)malloc(sizeof(char) * n.j + 1)))
			exit(-1);
		n.i = 0;
		while (av[n.cpt])
		{
			n.ex[n.i] = av[n.cpt];
			n.i++;
			n.cpt++;
		}
		n.ex[n.i] = '\0';
	}
	return (n.ex);
}

static char		*ft_find_extens(char *av)
{
	t_bonus	n;

	n.bol = 0;
	n.i = 0;
	n.ex = NULL;
	while (av[n.i])
	{
		if (av[n.i] == '.')
		{
			n.bol = 1;
			n.cpt = n.i;
			n.j = 0;
		}
		if (n.bol == 1)
			n.j++;
		n.i++;
	}
	return (ft_find(av, n));
}

int				ft_nbcolor(char *av)
{
	char	*ext;

	ext = ft_find_extens(av);
	if (ext)
	{
		if (ft_strcmp(ext, ".c") == 0)
			return (1);
		if (ft_strcmp(ext, ".o") == 0)
			return (2);
		else
			return (3);
	}
	return (4);
}
