/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 13:14:52 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 13:55:07 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	test(char *file, char *str)
{
	int i;

	i = -1;
	while (file[++i] &&
		(int)(ft_strlen(file) - ft_strlen(ft_strstr(file, str))) > i)
		if (file[i] != ' ' && file[i] != '\n')
			asm_error("Informations before name/comment", "");
}

void		hero_header(t_hero *hero, char *file, int *j)
{
	if (ft_strstr(file, NAME_CMD_STRING) && ft_strstr(file, COMMENT_CMD_STRING)
		&& ft_strlen(ft_strstr(file, NAME_CMD_STRING)) >
		ft_strlen(ft_strstr(file, COMMENT_CMD_STRING)))
	{
		test(file, ".name");
		hero->name = get_name(file, j);
		if (ft_strlen(hero->name) > PROG_NAME_LENGTH)
			error_size(0, hero->name);
		hero->size_inst = 0;
		hero->comment = get_comment(file, j);
		if (ft_strlen(hero->comment) > COMMENT_LENGTH)
			error_size(1, hero->comment);
	}
	else
	{
		test(file, ".comment");
		hero->comment = get_comment(file, j);
		if (ft_strlen(hero->comment) > COMMENT_LENGTH)
			error_size(1, hero->comment);
		hero->size_inst = 0;
		hero->name = get_name(file, j);
		if (ft_strlen(hero->name) > PROG_NAME_LENGTH)
			error_size(0, hero->name);
	}
}
