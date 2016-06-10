/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 21:30:43 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 12:34:11 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*newfile(char *filename)
{
	char	*new;
	char	*ext;
	int		length;

	if ((ext = ft_strrchr(filename, '.')))
	{
		if (ft_strlen(ext) == 2 && ext[1] == 's')
		{
			length = ft_strlen(filename) - 2;
			new = ft_strnew(length + 8);
			new = ft_strncat(new, filename, length);
			if (getflag('u'))
				new = ft_strcat(new, ".mor");
			else
				new = ft_strcat(new, ".cor");
			return (new);
		}
	}
	asm_error("not valid filename (file.s)", filename);
	return (NULL);
}

void	process(char *file, char *new)
{
	int		fd;
	t_hero	*hero;

	hero = read_hero(rmcomment(cleansource(readsource(file))));
	if (getflag('v'))
	{
		debug_hero(hero);
	}
	else
	{
		fd = open(new, O_CREAT | O_RDWR | O_TRUNC, 0600);
		ft_printf("Writing output program to %s\n", new);
		write_magicnumber(fd);
		write_name(fd, hero->name, hero->size_inst);
		write_comment(fd, hero->comment);
		write_instructions(fd, hero);
		close(fd);
	}
	free_hero(hero);
}

int		main(int ac, char **av)
{
	int		i;
	char	*new;

	if (ac < 2)
	{
		usage();
		return (0);
	}
	i = flagsload(ac, av);
	while (i < ac)
	{
		if (!(new = newfile(av[i])))
			asm_error("file name problem", "");
		else
		{
			process(av[i], new);
			ft_strdel(&new);
		}
		i++;
	}
	return (0);
}
