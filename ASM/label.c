/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:26:07 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 12:18:06 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		calc_dist_to_label(t_hero *hero, int start, int end)
{
	int	diff;
	int	size;

	size = 0;
	diff = end - start;
	if (diff < 0)
		size = sizebetweeninst(end, start, hero->inst) * -1;
	else
		size = sizebetweeninst(start, end, hero->inst);
	return (size);
}

char	*get_label_by_pos(t_hero *hero, int pos)
{
	int i;

	i = 0;
	while (i <= hero->countlabel)
	{
		if (hero->label_pos[i] == pos)
			return (hero->label_name[i]);
		i++;
	}
	return (NULL);
}

int		opthavelabel(char *opt)
{
	int	i;

	i = 0;
	while (islabelchar(opt[i]))
		i++;
	if (opt[i] == LABEL_CHAR && i > 0)
	{
		if (!opt[i + 1])
			return (1);
		return (2);
	}
	else
		return (0);
}

void	check_label_exist(t_hero *hero, char *label)
{
	int	i;

	i = 0;
	while (hero->label_name[i])
	{
		if (ft_strequ(label, hero->label_name[i]))
			return ;
		i++;
	}
	asm_error("reference to undefined label:", label);
}

int		get_pos_label(t_hero *hero, char *label)
{
	int	i;

	i = 0;
	while (hero->label_name[i])
	{
		if (ft_strequ(label, hero->label_name[i]))
			return (hero->label_pos[i]);
		i++;
	}
	return (0);
}
