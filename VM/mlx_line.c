/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:08:14 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 09:19:13 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

void			px_img(t_struck *s, float x, float y, int color)
{
	int index;

	if (x <= 0 || y <= 0 || x >= X || y >= Y)
		return ;
	index = y * s->img.sl + x * (s->img.bpp / 8);
	s->img.data[index] = color & 0x000000FF;
	s->img.data[index + 1] = (color & 0x0000FF00) >> 8;
	s->img.data[index + 2] = (color & 0x00FF0000) >> 16;
	s->img.data[index + 3] = (color & 0xFF000000) >> 24;
}

static float	init_rep(float diff_x, float diff_y)
{
	float	rep;

	rep = 0;
	if (fabs(diff_x) < fabs(diff_y))
		rep = (diff_y / diff_x) / 2;
	else
		rep = (diff_x / diff_y) / 2;
	return (rep);
}

static void		trace_line_bis(float diff_a, float diff_b, float *mod
		, float *rep)
{
	if (fabs(diff_a) < fabs(diff_b))
		*rep += diff_b / diff_a;
	if (*mod < diff_a)
		*mod += 1;
	if (*mod > diff_a)
		*mod -= 1;
}

void			line_px_img(t_struck *s, int *l, int col)
{
	float	x;
	float	y;
	float	rep;
	float	d[3];

	x = 0;
	y = 0;
	d[1] = l[1] - l[3];
	d[2] = l[0] - l[2];
	rep = init_rep(d[2], d[1]);
	while (x != d[2] || y != d[1])
	{
		px_img(s, l[0] - x, l[1] - y, col);
		if ((fabs(d[2]) >= fabs(d[1])) || fabs(y) >= fabs(rep))
			trace_line_bis(d[2], d[1], &x, &rep);
		if ((fabs(d[1]) >= fabs(d[2])) || fabs(x) >= fabs(rep))
			trace_line_bis(d[1], d[2], &y, &rep);
	}
}
