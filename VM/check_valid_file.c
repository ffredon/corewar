/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:52:37 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 09:19:04 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static int		check_order(t_struck *s, char *nb)
{
	int		i;

	i = 0;
	if (s->tmp[2])
		cor_err(6, "-n");
	if (nb && (nb[i] == '-' || nb[i] == '+'))
		i++;
	while (nb && nb[i])
	{
		if (!ft_isdigit(nb[i]))
		{
			s->tmp[2] = 1;
			return (0);
		}
		i++;
	}
	if (!nb || !ft_atoi(nb) || ft_atoi(nb) < INT_MIN || ft_atoi(nb) > INT_MAX)
		cor_err(6, "-n");
	s->tmp[1] = ft_atoi(nb);
	s->tmp[2] = 1;
	return (1);
}

static void		check_dump(t_struck *s, char *nb)
{
	int		i;
	long	j;

	i = 0;
	j = 0;
	while (ft_isdigit(nb[i]))
		++i;
	if (nb[i] || (j = ft_atoi(nb)) > INT_MAX || !j)
		cor_err(6, "-dump");
	if (s->dump != -1)
		cor_err(7, "-dump");
	s->dump = j;
}

static void		check_turn(t_struck *s, char *nb)
{
	int		i;
	long	j;

	i = 0;
	j = 0;
	while (ft_isdigit(nb[i]))
		++i;
	if (nb[i] || (j = ft_atoi(nb)) > INT_MAX || !j)
		cor_err(6, "-turn");
	if (s->turn_dump != -1)
		cor_err(7, "-turn");
	s->turn_dump = j;
	s->rep ^= DUMP;
}

static int		check_valid_file_next(t_struck *s, char **files, int *i)
{
	if (ft_strrchr(files[*i], '.')
		&& ft_strequ(ft_strrchr(files[*i], '.'), ".cor"))
		check_champion(s, files[*i], open(files[*i], O_RDONLY));
	else if (ft_strequ(files[*i], "-n"))
	{
		(!files[*i + 1]) ? cor_err(8, "-n") : 1;
		if (!check_order(s, files[++*i]))
			--*i;
	}
	else if (ft_strequ(files[*i], "-dump"))
	{
		(!files[*i + 1]) ? cor_err(8, "-dump") : 1;
		check_dump(s, files[++*i]);
	}
	else if (ft_strequ(files[*i], "-g"))
	{
		s->rep ^= GRAPH;
		if (!(s->rep & GRAPH))
			cor_err(7, "-g");
	}
	else
		return (0);
	return (1);
}

void			check_valid_file(t_struck *s, char **files, int i)
{
	while (files[++i])
	{
		if (check_valid_file_next(s, files, &i))
			;
		else if (ft_strequ(files[i], "-a"))
			i = ft_opt_a(s, i);
		else if (ft_strequ(files[i], "-turn"))
		{
			(!files[i + 1]) ? cor_err(8, "-turn") : 1;
			check_turn(s, files[++i]);
		}
		else
			cor_err(2, files[i]);
	}
	(!s->nb_chp) ? cor_err(15, NULL) : 1;
	(s->tmp[2]) ? cor_err(9, NULL) : 1;
	reorg(s);
	intro_players(s);
	i = -1;
	while (++i < s->nb_chp)
	{
		s->chp[i].tmp[0] = 0;
		s->chp[i].last_live = 0;
	}
}
