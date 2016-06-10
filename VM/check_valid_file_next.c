/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_file_next.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:19:30 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/24 18:26:27 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

void			reorg(t_struck *s)
{
	t_champ		*chp;
	int			tmp;
	int			i;
	int			j;

	i = 0;
	chp = s->chp;
	while (i < (int)s->nb_chp)
	{
		while (i < (int)s->nb_chp && chp[i].tmp[1])
			i++;
		tmp = 3;
		while (i < (int)s->nb_chp && tmp != (chp[i].tmp[0]))
		{
			j = -1;
			tmp = chp[i].tmp[0];
			while (++j < (int)s->nb_chp)
				if (chp[j].tmp[1] && chp[i].tmp[0] == chp[j].tmp[1])
					chp[i].tmp[0]--;
		}
		chp[i].tmp[1] = tmp;
		i++;
	}
}

void			intro_players(t_struck *s)
{
	int i;

	i = -1;
	while (++i < s->nb_chp)
	{
		ft_printf("* Player %d (%d), weighing %d bytes, \"%s\" (\"%s\") !\n",
			i + 1, s->chp[i].tmp[1], s->chp[i].op_len,
			s->chp[i].name, s->chp[i].comment);
	}
}

static void		checkdoublename(t_struck *s)
{
	t_champ			*chp;
	int				i;

	i = 0;
	chp = s->chp;
	while (i <= (int)s->nb_chp)
	{
		if (chp[i].tmp[1] == s->tmp[1])
			cor_err(6, "-n");
		i++;
	}
}

static void		check_champion_next(t_struck *s, char *file, int fd, int i)
{
	i = read(fd, s->chp[(int)s->nb_chp].comment, 2052);
	(!(s->chp[(int)s->nb_chp].op = (unsigned char*)ft_memalloc(700)))
	? cor_err(4, NULL) : 1;
	i = read(fd, s->chp[(int)s->nb_chp].op, 700);
	if (i != s->chp[(int)s->nb_chp].op_len)
		cor_err(13, (ft_strrchr(file, '/')) ? ft_strrchr(file, '/') + 1 : file);
	if (i > 682)
		cor_err(12, (ft_strrchr(file, '/')) ? ft_strrchr(file, '/') + 1 : file);
	if (s->tmp[1])
	{
		checkdoublename(s);
		s->chp[(int)s->nb_chp].tmp[1] = s->tmp[1];
	}
	else
	{
		s->chp[(int)s->nb_chp].tmp[0] = s->tmp[0];
		s->chp[(int)s->nb_chp].tmp[1] = 0;
		s->tmp[0]--;
	}
	s->tmp[1] = 0;
	s->tmp[2] = 0;
	++s->nb_chp;
}

void			check_champion(t_struck *s, char *file, int fd)
{
	int				i;
	unsigned char	*line;

	if (s->nb_chp >= MAX_PLAYERS)
		cor_err(5, NULL);
	if (fd <= 0)
		cor_err(2, (ft_strrchr(file, '/')) ? ft_strrchr(file, '/') + 1 : file);
	(!(line = ft_memalloc(5))) ? cor_err(4, NULL) : 1;
	if ((i = read(fd, line, 4)) <= 0)
		cor_err(2, (ft_strrchr(file, '/')) ? ft_strrchr(file, '/') + 1 : file);
	if (str_to_int(line, 4) != COREWAR_EXEC_MAGIC)
		cor_err(3, NULL);
	free(line);
	(!(s->chp[(int)s->nb_chp].name = ft_memalloc(255))) ? cor_err(4, NULL) : 1;
	i = read(fd, s->chp[(int)s->nb_chp].name, 132);
	i = read(fd, line, 4);
	s->chp[(int)s->nb_chp].op_len = str_to_int(line, 4);
	(!(s->chp[(int)s->nb_chp].comment = ft_memalloc(2048)))
	? cor_err(4, NULL) : 1;
	check_champion_next(s, file, fd, i);
}
