/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 13:56:19 by tauvray           #+#    #+#             */
/*   Updated: 2015/10/28 12:02:46 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termios.h>
# include <unistd.h>
# include <termcap.h>
# include <signal.h>
# include <fcntl.h>
# include <sgtty.h>
# include <sys/ioctl.h>

# define UP buffer[0] == 27 && buffer[1] == 79 && buffer[2] == 65
# define DOWN buffer[0] == 27 && buffer[1] == 79 && buffer[2] == 66
# define RIGHT buffer[0] == 27 && buffer[1] == 79 && buffer[2] == 67
# define LEFT buffer[0] == 27 && buffer[1] == 79 && buffer[2] == 68
# define SPACE buffer[0] == 32 && buffer[1] == 0 && buffer[2] == 0
# define SUPPR buffer[0] == 126 && buffer[1] == 0 && buffer[2] == 0
# define ENTER buffer[0] == 10 && buffer[1] == 0 && buffer[2] == 0
# define CTRLD buffer[0] == 4 && buffer[1] == 0 && buffer[2] == 0
# define ECHAP buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0
# define IKEY buffer[0] == 105 && buffer[1] == 0 && buffer[2] == 0
# define RKEY buffer[0] == 114 && buffer[1] == 0 && buffer[2] == 0
# define AKEY buffer[0] == 113 && buffer[1] == 0 && buffer[2] == 0
# define HOME buffer[0] == 27 && buffer[1] == 79 && buffer[2] == 72
# define END buffer[0] == 27 && buffer[1] == 79 && buffer[2] == 70
# define QKEY buffer[0] == 97 && buffer[1] == 0 && buffer[2] == 0

# define MARGIN 10
# define MARGINY 2

typedef struct		s_struct
{
	int				fd;
	struct termios	save_term;
	int				maxwidth;
	int				maxheight;
	int				ww;
	int				wh;
	int				nbrelem;
	t_sel			*lst;
}					t_struct;

typedef struct		s_cpt
{
	int				i;
	int				j;
}					t_cpt;

typedef struct		s_show
{
	int				x;
	int				y;
	int				nbx;
	int				nby;
	int				margex;
}					t_show;

typedef struct		s_bonus
{
	char			*ex;
	int				i;
	int				j;
	int				cpt;
	int				bol;
}					t_bonus;

typedef struct		s_tri
{
	t_sel	*head;
	t_sel	*p;
	t_sel	*q;
	t_sel	*min;
	char	*tmp;
	char	*tmp1;
	int		actif;
	char	*tmp2;
	int		ds;
	int		col_tmp;
}					t_tri;

t_struct			g_elem;

void				ft_trialreverse(void);
void				ft_return_values();
void				ft_undo();
void				ft_reverse();
void				ft_signal(void);
int					ft_small(int ww, int maxwidth);
void				ft_home(void);
void				ft_end(void);
void				ft_key2(char *buffer);
int					ft_init(struct termios *term);
void				ft_key(char *buffer, int ww, int maxheight);
void				ft_move_left_spe2(int i, int j, t_sel *head);
int					my_outc(int c);
t_sel				*ft_makelist(char **av, int ac);
void				ft_select();
int					ft_count_height(int ww, int maxheight);
int					ft_count_line(int maxwidth);
void				ft_show_too_small(void);
int					ft_findmax(t_sel *head);
void				ft_quit_term(void);
int					ft_count_list(void);
void				ft_move_left_spe(void);
void				ft_pos(int x, int y, t_sel *head);
int					ft_nbcolor(char *av);
void				ft_move_pos(int pox, int posy);
void				ft_show(int maxwidth, int maxheight, int ww);
int					ft_resetterm(void);
void				ft_move(int ww, int maxheight);
void				ft_move_right(void);
void				ft_move_left(void);
void				ft_move_up(int ww, int maxheight);
void				ft_move_down(int ww, int maxheight);
void				ft_selection(void);
void				do_op(int w);
void				ft_del_first(t_sel *supp_element);
void				ft_del2(t_sel *courant, t_sel *supp_element);
void				ft_del(void);
void				control_z(int w);
void				ft_fg(int w);
void				ft_trial(void);

#endif
