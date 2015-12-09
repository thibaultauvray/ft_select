/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaire2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 17:14:41 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/24 12:22:29 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_del2(t_sel *courant, t_sel *supp_element)
{
	while (courant)
	{
		if (courant->next->actif == 1)
		{
			courant->actif = 1;
			break ;
		}
		courant = courant->next;
	}
	supp_element = courant->next;
	courant->next = courant->next->next;
	free(supp_element);
}

int		ft_count_line(int maxwidth)
{
	size_t		max;
	int			i;
	int			x;
	t_sel		*head;

	head = g_elem.lst;
	max = ft_findmax(head);
	i = 0;
	x = 0;
	while (g_elem.lst)
	{
		i += max;
		x++;
		if (i > maxwidth)
		{
			g_elem.lst = head;
			return (x);
		}
		g_elem.lst = g_elem.lst->next;
	}
	g_elem.lst = head;
	return (x);
}

t_sel	*ft_makelist(char **av, int ac)
{
	t_sel	*lst;
	t_sel	*tmp;
	int		i;
	int		fd;

	i = 1;
	tmp = NULL;
	lst = NULL;
	while (i != ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			tmp = ft_lstnewsel(av[i], ft_strlen(av[i]), 0);
		else
			tmp = ft_lstnewsel(av[i], ft_strlen(av[i]), ft_nbcolor(av[i]));
		if (i == ac - 1)
			tmp->actif = 1;
		ft_lstaddsel(&lst, tmp);
		tmp = NULL;
		close(fd);
		i++;
	}
	return (lst);
}

void	ft_fg(int w)
{
	struct termios term;
	struct winsize ws;

	(void)w;
	ioctl(0, TIOCGWINSZ, &ws);
	g_elem.maxwidth = ws.ws_col;
	g_elem.maxheight = ws.ws_row;
	ft_init(&term);
	signal(SIGTSTP, control_z);
	ft_show(g_elem.maxwidth, g_elem.maxheight, ft_count_line(g_elem.maxwidth));
}

void	control_z(int w)
{
	char	cp[2];

	cp[0] = g_elem.save_term.c_cc[VSUSP];
	cp[1] = 0;
	(void)w;
	tputs(tgetstr("ke", NULL), g_elem.fd, my_outc);
	tputs(tgetstr("te", NULL), g_elem.fd, my_outc);
	ft_resetterm();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}
