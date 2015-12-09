/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 17:07:59 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/27 16:48:35 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_init(struct termios *term)
{
	char	*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if ((tgetent(NULL, name_term)) <= 0)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	g_elem.save_term = *term;
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_lflag |= ISIG;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	if ((g_elem.fd = open("/dev/tty", O_RDWR)) == -1)
		exit(1);
	tputs(tgetstr("ti", NULL), g_elem.fd, my_outc);
	tputs(tgetstr("vi", NULL), g_elem.fd, my_outc);
	return (1);
}

int		ft_resetterm(void)
{
	tputs(tgetstr("ve", NULL), g_elem.fd, my_outc);
	tputs(tgetstr("te", NULL), g_elem.fd, my_outc);
	if (tcsetattr(0, 0, &g_elem.save_term) == -1)
		return (-1);
	return (1);
}
