/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 21:30:43 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/24 21:24:21 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_to_hexa(int fd, long nb, int size)
{
	char	*hexa;

	hexa = to_hexa(nb, size);
	write(fd, hexa, size);
	ft_memdel((void**)&hexa);
}

void	write_name(int fd, char *name, int size)
{
	char	*gname;

	gname = ft_strnew(PROG_NAME_LENGTH + 6);
	gname = ft_strcat(gname, name);
	write(fd, gname, PROG_NAME_LENGTH + 6);
	write_to_hexa(fd, size, 2);
	ft_strdel(&gname);
}

void	write_comment(int fd, char *comment)
{
	char	*gcomment;

	gcomment = ft_strnew(COMMENT_LENGTH + 4);
	gcomment = ft_strcat(gcomment, comment);
	write(fd, gcomment, COMMENT_LENGTH + 4);
	ft_strdel(&gcomment);
}

void	write_magicnumber(int fd)
{
	char	c[4];

	c[0] = (char)((COREWAR_EXEC_MAGIC & 0xff000000) >> 24);
	c[1] = (char)((COREWAR_EXEC_MAGIC & 0xff0000) >> 16);
	c[2] = (char)((COREWAR_EXEC_MAGIC & 0xff00) >> 8);
	c[3] = (char)(COREWAR_EXEC_MAGIC & 0xff);
	write(fd, c, 4);
}

void	write_instructions(int fd, t_hero *hero)
{
	t_inst	*tmp;
	int		line;

	line = 0;
	tmp = hero->inst;
	while (tmp)
	{
		write_instruction(fd, hero, tmp, line);
		tmp = tmp->next;
		line++;
	}
}
