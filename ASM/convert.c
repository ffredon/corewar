/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 14:04:34 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/24 15:35:18 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	g_op_tab[17];

char	*to_hexa(long nb, int size)
{
	char	*out;
	int		i;
	int		u;
	int		d;

	if (nb < 0)
		nb = (ft_pow(16, size * 2) + nb);
	d = 0;
	u = 0xff;
	i = size - 1;
	out = ft_strnew(size + 1);
	while (i >= 0)
	{
		out[i] = (nb & (u)) >> d;
		u *= 256;
		d += 8;
		i--;
	}
	if ((nb & (u)) >> d)
	{
		i = size - 1;
		while (i > 0)
			out[i--] = 0xff;
	}
	return (out);
}

int		toc(int a)
{
	if (a == 4)
		a = 3;
	return (a);
}

int		tosize(int a, int inst_type)
{
	if (a == T_REG)
		return (REG_SIZE);
	if (a == T_DIR)
	{
		if (g_op_tab[inst_type].truc)
			return (DIR_SIZE / 2);
		else
			return (DIR_SIZE);
	}
	if (a == T_IND)
		return (IND_SIZE);
	return (0);
}

int		t_dir_val(t_param *param, int line, t_hero *hero)
{
	char	*label;

	if (param->str[1] != LABEL_CHAR)
		return (ft_atoi(&param->str[1]));
	else
	{
		label = &param->str[2];
		return (calc_dist_to_label(hero, line, get_pos_label(hero, label)));
	}
}

int		t_ind_val(t_param *param, int line, t_hero *hero)
{
	char	*label;

	if (param->str[0] != LABEL_CHAR)
		return (ft_atoi(param->str));
	else
	{
		label = &param->str[1];
		return (calc_dist_to_label(hero, line, get_pos_label(hero, label)));
	}
}
