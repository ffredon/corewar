/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 05:49:45 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 12:49:05 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*optgetlabelname(char *opt)
{
	int	i;

	i = 0;
	while (islabelchar(opt[i]))
	{
		i++;
	}
	return (ft_strsub(opt, 0, i));
}

void	split_op_label_line(t_hero *hero, char **tmpopts, int *op, int line)
{
	if (opthavelabel(hero->opts[line]) == 1)
	{
		hero->label_name[hero->countlabel] = optgetlabelname(hero->opts[line]);
		hero->label_pos[hero->countlabel] = *op;
		hero->countlabel++;
	}
	else if (opthavelabel(hero->opts[line]) == 2)
	{
		hero->label_name[hero->countlabel] = optgetlabelname(hero->opts[line]);
		hero->label_pos[hero->countlabel] = *op;
		tmpopts[*op] = ft_strtrimfree(ft_strsub(hero->opts[line],
			ft_strlen(hero->label_name[hero->countlabel]) + 1,
			ft_strlen(hero->opts[line]) -
			ft_strlen(hero->label_name[hero->countlabel])));
		(*op)++;
		hero->countlabel++;
	}
	else if (ft_strlen(hero->opts[line]) > 0)
	{
		tmpopts[*op] = ft_strdup(hero->opts[line]);
		(*op)++;
	}
}

void	split_op_label(t_hero *hero)
{
	char	**tmpopts;
	int		op;
	int		line;

	line = 0;
	op = 0;
	tmpopts = (char **)malloc(sizeof(char *) * (ft_tablen(hero->opts) + 1));
	hero->label_pos = ft_memalloc(sizeof(int) * (ft_tablen(hero->opts) + 1));
	hero->label_name = ft_memalloc(sizeof(char*) * (ft_tablen(hero->opts) + 1));
	hero->countlabel = 0;
	while (hero->opts[line])
	{
		hero->opts[line] = ft_strtrimfree(hero->opts[line]);
		split_op_label_line(hero, tmpopts, &op, line);
		line++;
	}
	tmpopts[op] = NULL;
	ft_tabfree(hero->opts);
	hero->opts = tmpopts;
}

char	**readops(char *file)
{
	char **tab;

	tab = ft_strsplit(file, '\n');
	return (tab);
}
