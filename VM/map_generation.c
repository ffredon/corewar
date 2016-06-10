/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 20:47:46 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 09:20:22 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

int					ft_opt_a(t_struck *s, int i)
{
	s->rep ^= AFF;
	if (!(s->rep & AFF))
		cor_err(7, "-a");
	return (i);
}

void				print_map(t_struck *s, int j)
{
	int i;

	i = -1;
	system("clear");
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("0x%*.*llx : ", 4, 4, 64 * j++);
		if (s->proc_test[i])
			ft_printf("\e[7;36m%2.2x\e[0;0m", (char)s->map[i] & 0xff);
		else if (s->col_chp[i])
		{
			if (s->col_chp[i] == 1)
				ft_printf("{CGREEN%2.2x}", (char)s->map[i] & 0xff);
			else if (s->col_chp[i] == 2)
				ft_printf("{CRED%2.2x}", (char)s->map[i] & 0xff);
			else if (s->col_chp[i] == 3)
				ft_printf("{CBLUE%2.2x}", (char)s->map[i] & 0xff);
			else if (s->col_chp[i] == 4)
				ft_printf("\e[0;35m%2.2x\e[0;0m", (char)s->map[i] & 0xff);
		}
		else
			ft_printf("%2.2x", s->map[i]);
		(i % 64 == 63 && i) ? write(1, "\n", 1) : write(1, " ", 1);
	}
}

void				print_map_dump(t_struck *s)
{
	int i[2];

	i[0] = -1;
	i[1] = 0;
	system("clear");
	while (++i[0] < MEM_SIZE)
	{
		if (i[0] % 32 == 0)
			ft_printf("0x%*.*llx : ", 4, 4, 32 * i[1]++);
		if (s->col_chp[i[0]])
		{
			if (s->col_chp[i[0]] == 1)
				ft_printf("{CGREEN%2.2x}", (char)s->map[i[0]] & 0xff);
			else if (s->col_chp[i[0]] == 2)
				ft_printf("{CRED%2.2x}", (char)s->map[i[0]] & 0xff);
			else if (s->col_chp[i[0]] == 3)
				ft_printf("{CBLUE%2.2x}", (char)s->map[i[0]] & 0xff);
			else if (s->col_chp[i[0]] == 4)
				ft_printf("\e[0;35m%2.2x\e[0;0m", (char)s->map[i[0]] & 0xff);
		}
		else
			ft_printf("%2.2x", s->map[i[0]]);
		(i[0] % 32 == 31 && i[0]) ? write(1, "\n", 1) : write(1, " ", 1);
	}
}

static void			add_lst(t_pc **proc, int i, char champ, t_champ chp)
{
	t_pc	*tmp;
	int		j;

	(!(tmp = ft_memalloc(sizeof(t_pc)))) ? cor_err(4, NULL) : 1;
	tmp->index = i;
	tmp->chp = champ;
	tmp->cycle = 0;
	tmp->carry = 0;
	tmp->live = 0;
	tmp->instruc = 0;
	tmp->no = 0;
	j = -1;
	ft_bzero(tmp->tmp, 3);
	while (++j < REG_NUMBER)
		ft_bzero(tmp->reg[j], REG_SIZE);
	ft_memcpy(tmp->reg[0], &chp.tmp[1], 4);
	if (!*proc)
		*proc = tmp;
	else
	{
		tmp->next = *proc;
		*proc = tmp;
	}
}

void				map_gen(t_struck *s, t_pc **proc, int j,
	unsigned long long *i)
{
	while ((char)++j < s->nb_chp && (i[0] = -4))
	{
		i[1] = MEM_SIZE * j / s->nb_chp;
		add_lst(proc, i[1], j + 1, s->chp[j]);
		while ((int)(i[0] += 4) < s->chp[j].op_len)
		{
			i[2] = str_to_int(s->chp[j].op + i[0], 4);
			s->map[i[1]] = ((i[2] & 0xff000000) >> 24);
			s->col_chp[i[1]] = j + 1;
			if ((int)i[0] + 1 >= s->chp[j].op_len)
				break ;
			s->col_chp[i[1] + 1] = j + 1;
			s->map[i[1] + 1] = ((i[2] & 0x00ff0000) >> 16);
			if ((int)i[0] + 2 >= s->chp[j].op_len)
				break ;
			s->col_chp[i[1] + 2] = j + 1;
			s->map[i[1] + 2] = ((i[2] & 0x0000ff00) >> 8);
			if ((int)i[0] + 3 >= s->chp[j].op_len)
				break ;
			s->map[i[1] + 3] = (i[2] & 0x000000ff);
			s->col_chp[i[1] + 3] = j + 1;
			i[1] += 4;
		}
	}
}
