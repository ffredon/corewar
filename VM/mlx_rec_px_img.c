/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rec_px_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 08:59:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 09:20:02 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void	rec_px_img_truc(int *c, t_struck *s, int *i)
{
	i[0] = c[1] * s->img.sl + c[0] * (s->img.bpp / 8);
	i[1] = c[1] * s->img.sl + (c[0] + 1) * (s->img.bpp / 8);
	i[2] = (c[1] + 1) * s->img.sl + (c[0]) * (s->img.bpp / 8);
	i[3] = (c[1] - 1) * s->img.sl + (c[0]) * (s->img.bpp / 8);
	i[4] = (c[1]) * s->img.sl + (c[0] - 1) * (s->img.bpp / 8);
}

static void	rec_px_img_truc2(t_struck *s, int (*f)(int i), int color, int *i)
{
	s->img.data[i[0]] = f(fmod(color, 999)) & 0x000000FF;
	s->img.data[i[0] + 1] = (f(fmod(color, 999)) & 0x0000FF00) >> 8;
	s->img.data[i[0] + 2] = (f(fmod(color, 999)) & 0x00FF0000) >> 16;
	s->img.data[i[0] + 3] = (f(fmod(color, 999)) & 0xFF000000) >> 24;
}

static void	rec_px_img_truc3(t_struck *s, int (*f)(int i), int *c, int color)
{
	int i[5];

	rec_px_img_truc(c, s, i);
	if (!s->img.data[i[1]] && !s->img.data[i[1] + 1] &&
		!s->img.data[i[1] + 2] && !s->img.data[i[1] + 3])
	{
		c[0]++;
		rec_px_img(s, c, f, color + 3);
		c[0]--;
	}
	if (!s->img.data[i[2]] && !s->img.data[i[2] + 1] &&
		!s->img.data[i[2] + 2] && !s->img.data[i[2] + 3])
	{
		c[1]++;
		rec_px_img(s, c, f, color + 3);
		c[1]--;
	}
}

static void	rec_px_img_truc4(t_struck *s, int (*f)(int i), int *c, int color)
{
	int i[5];

	rec_px_img_truc(c, s, i);
	if (!s->img.data[i[3]] && !s->img.data[i[3] + 1] &&
		!s->img.data[i[3] + 2] && !s->img.data[i[3] + 3])
	{
		c[1]--;
		rec_px_img(s, c, f, color + 3);
		c[1]++;
	}
	if (!s->img.data[i[4]] && !s->img.data[i[4] + 1] &&
		!s->img.data[i[4] + 2] && !s->img.data[i[4] + 3])
	{
		c[0]--;
		rec_px_img(s, c, f, color + 3);
		c[0]++;
	}
}

void		rec_px_img(t_struck *s, int *c, int (*f)(int i), int color)
{
	int i[5];

	rec_px_img_truc(c, s, i);
	if (c[0] <= 0 || c[1] <= 0 || c[0] >= X || c[1] >= Y || s->img.data[i[0]] ||
		s->img.data[i[0] + 1] || s->img.data[i[0] + 2] || s->img.data[i[0] + 3])
		return ;
	rec_px_img_truc2(s, f, color, i);
	rec_px_img_truc3(s, f, c, color);
	rec_px_img_truc4(s, f, c, color);
}
