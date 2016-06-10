/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_shapes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:00:31 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 09:00:44 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

void	cercle(int *c, int (*f)(int i), int col, t_struck *s)
{
	double rayon;
	double centre_x;
	double centre_y;
	double angle;

	angle = 0.0;
	rayon = 10.0 * s->img.zoom;
	while (angle < M_PI * 2)
	{
		centre_x = c[0] + rayon * -cos(angle);
		centre_y = c[1] + rayon * -sin(angle);
		px_img(s, (int)centre_x, (int)centre_y, col);
		angle += 0.01;
	}
	rec_px_img(s, c, f, col);
}

void	triangle(int *c, int (*f)(int i), int col, t_struck *s)
{
	int l[4];

	l[0] = c[0];
	l[1] = c[1] - 10 * s->img.zoom;
	l[2] = c[0] - 10 * s->img.zoom;
	l[3] = c[1] + 10 * s->img.zoom;
	line_px_img(s, l, col);
	l[0] = c[0] - 10 * s->img.zoom;
	l[1] = c[1] + 10 * s->img.zoom;
	l[2] = c[0] + 10 * s->img.zoom;
	l[3] = c[1] + 10 * s->img.zoom;
	line_px_img(s, l, col);
	l[0] = c[0];
	l[1] = c[1] - 10 * s->img.zoom;
	l[2] = c[0] + 10 * s->img.zoom;
	l[3] = c[1] + 10 * s->img.zoom;
	line_px_img(s, l, col);
	rec_px_img(s, c, f, col);
}

void	star(int *c, int (*f)(int i), int col, t_struck *s)
{
	static int	a[50] = {STAR};
	int			l[4];
	int			u;

	u = 0;
	while (u <= 10)
	{
		l[0] = c[0] + a[(u * 4 + 0)] * s->img.zoom;
		l[1] = c[1] + a[(u * 4 + 1)] * s->img.zoom;
		l[2] = c[0] + a[(u * 4 + 2)] * s->img.zoom;
		l[3] = c[1] + a[(u * 4 + 3)] * s->img.zoom;
		line_px_img(s, l, col);
		u++;
	}
	rec_px_img(s, c, f, col);
}
