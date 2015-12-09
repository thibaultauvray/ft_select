/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 14:40:04 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/28 12:02:47 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_return_values(void)
{
	t_sel			*tmp;
	int				i;
	int				l;

	i = 1;
	l = 0;
	ft_resetterm();
	tputs(tgetstr("te", NULL), g_elem.fd, my_outc);
	while (i != g_elem.nbrelem + 1)
	{
		i++;
		if (g_elem.lst->select == 1)
		{
			write(1, g_elem.lst->content, g_elem.lst->content_size);
			write(1, " ", 1);
			l++;
		}
		tmp = g_elem.lst->next;
		free(g_elem.lst);
		g_elem.lst = tmp;
	}
	if (l != 0)
		write(1, "\n", 1);
	close(g_elem.fd);
	exit(1);
}

void	ft_show_too_small(void)
{
	tputs(tgetstr("cl", NULL), g_elem.fd, my_outc);
	write(g_elem.fd, "Windows too small\n", 18);
}

int		ft_small(int ww, int maxwidth)
{
	int		max;
	t_sel	*head;

	head = g_elem.lst;
	max = ft_findmax(head);
	if (ww == 2)
	{
		if ((max * 2) > maxwidth)
			return (-1);
	}
	return (1);
}

void	ft_signal(void)
{
	signal(SIGWINCH, do_op);
	signal(SIGTSTP, control_z);
	signal(SIGCONT, ft_fg);
	signal(SIGINT, do_op);
	signal(SIGSEGV, do_op);
	signal(SIGBUS, do_op);
	signal(SIGTERM, do_op);
	signal(SIGQUIT, do_op);
	signal(SIGABRT, do_op);
	signal(SIGKILL, do_op);
}

int		main(int ac, char **av)
{
	struct termios	term;

	if (ac == 1)
		ft_putstr_fd("usage : ./ft_select [file1] [file2] [...]\n", 2);
	else
	{
		ft_signal();
		if (ft_init(&term) == -1)
		{
			ft_putstr_fd("Try to remove the env -i\n", 2);
			return (-1);
		}
		g_elem.lst = ft_makelist(av, ac);
		g_elem.nbrelem = ac - 1;
		ft_select();
		ft_resetterm();
	}
}
