/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:48:38 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 10:57:41 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void	init_struct(t_struck *s)
{
	s->rep = 0;
	s->tmp[0] = -1;
	s->tmp[1] = 0;
	s->tmp[2] = 0;
	s->max = 0;
	s->cycle = 0;
	s->nb_chp = 0;
	s->dump = -1;
	s->check = 0;
	s->live = 0;
	s->turn = 7;
	s->turn_dump = -1;
	Mix_AllocateChannels(32);
	s->sound[0] = NULL;
	s->sound[1] = NULL;
	s->music = NULL;
	ft_bzero(s->proc_live[1], MEM_SIZE);
	if (!(s->map = ft_memalloc(sizeof(char) * MEM_SIZE + 4)))
		cor_err(4, NULL);
	if (!(s->col_chp = ft_memalloc(sizeof(char) * MEM_SIZE + 4)))
		cor_err(4, NULL);
}

void		cor_errors1(char nb, char *str)
{
	char	*err;

	if (nb == 9)
		err = "Champion needed after option -n";
	else if (nb == 10)
		err = "Too many champions in the same place";
	else if (nb == 11)
		err = " too long";
	else if (nb == 12)
		err = " is too big, 682 bytes is the limit.";
	else if (nb == 13)
		err = " has a code size that differ from what its header says.\n";
	else if (nb == 14)
		err = " failed.";
	else if (nb == 15)
		err = "One champion is needed.";
	if (nb == 11 || nb == 12 || nb == 13 || nb == 14)
		ft_putstr_fd(str, 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void		cor_err(char nb, char *str)
{
	char	*err;

	if (nb == 1)
		err = "Wrong number of arguments";
	else if (nb == 2)
		err = "Can't read the file : ";
	else if (nb == 3)
		err = "Wrong Header at the top of the file";
	else if (nb == 4)
		err = "Malloc failed";
	else if (nb == 5)
		err = "Too many champions";
	else if (nb == 6)
		err = "Wrong format for option ";
	else if (nb == 7)
		err = "Already a value for option ";
	else if (nb == 8)
		err = "Value needed for option ";
	else if (nb > 8)
		cor_errors1(nb, str);
	ft_putstr_fd(err, 2);
	if (nb == 2 || nb == 6 || nb == 7 || nb == 8)
		ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void		ft_usage(void)
{
	ft_printf("Usage: ./corewar [-g -a -n N -dump N | -turn N] ");
	ft_printf("<champion1.cor> <...>\n");
	ft_printf("-n N      : Champion number\n");
	ft_printf("#### TEXT OUTPUT MODE ##################################\n");
	ft_printf("-a   : print AFF and LIVE\n");
	ft_printf("-dump N   : Dumps memory after N cycles then exits\n");
	ft_printf("-turn N   : Dumps memory every N cycles\n");
	ft_printf("#### GRAPHICAL OUTPUT MODE #############################\n");
	ft_printf("-g        : Graphic mode\n");
	ft_printf("########################################################\n");
	exit(1);
}

int			main(int argc, char **argv)
{
	t_struck			s;
	t_pc				*proc;
	unsigned long long	i[3];

	if (argc == 1)
		ft_usage();
	init_struct(&s);
	proc = NULL;
	check_valid_file(&s, argv, 0);
	map_gen(&s, &proc, -1, i);
	s.pro = &proc;
	if (s.rep & GRAPH)
	{
		init_graph(&s);
		mlx_hook(s.img.win, 2, (1l << 0), key_functions, &s);
		mlx_hook(s.img.menu, 2, (1l << 0), key_functions, &s);
		s.rep ^= STOP;
		mlx_loop_hook(s.img.mlx, aff_graph, &s);
		mlx_loop(s.img.mlx);
	}
	else
		launching_vm(&s);
	return (0);
}
