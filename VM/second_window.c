/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 19:53:08 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 08:17:52 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"
#include "window.h"

static void			put_players_one(t_struck *s)
{
	char *tmp;

	mlx_string_put(M, s->img.menu, 10, 160, black(900), "Player 1 : ");
	mlx_string_put(M, s->img.menu, 120, 160, burn(100), s->chp[0].name);
	mlx_string_put(M, s->img.menu, 40, 190, black(900), "Last live     : ");
	tmp = ft_itoa(s->chp[0].last_live);
	mlx_string_put(M, s->img.menu, 200, 190, burn(100), tmp);
	free(tmp);
	tmp = ft_itoa(s->chp[0].tmp[0]);
	mlx_string_put(M, s->img.menu, 40, 210, black(900), "Current lives : ");
	mlx_string_put(M, s->img.menu, 200, 210, burn(100), tmp);
	free(tmp);
}

static void			put_players_two(t_struck *s)
{
	char *tmp;

	mlx_string_put(M, s->img.menu, 10, 260, black(900), "Player 2 : ");
	mlx_string_put(M, s->img.menu, 120, 260, I(200), s->chp[1].name);
	mlx_string_put(M, s->img.menu, 40, 300, black(900), "Last live     : ");
	tmp = ft_itoa(s->chp[1].last_live);
	mlx_string_put(M, s->img.menu, 200, 300, I(200), tmp);
	free(tmp);
	tmp = ft_itoa(s->chp[1].tmp[0]);
	mlx_string_put(M, s->img.menu, 40, 320, black(900), "Current lives : ");
	mlx_string_put(M, s->img.menu, 200, 320, I(200), tmp);
	free(tmp);
}

static void			put_players_three(t_struck *s)
{
	char *tmp;

	mlx_string_put(M, s->img.menu, 10, 360, black(900), "Player 3 : ");
	mlx_string_put(M, s->img.menu, 120, 360,
		ft_colors_mag(700), s->chp[2].name);
	mlx_string_put(M, s->img.menu, 40, 390, black(900), "Last live     : ");
	tmp = ft_itoa(s->chp[2].last_live);
	mlx_string_put(M, s->img.menu, 200, 390, ft_colors_mag(700), tmp);
	free(tmp);
	tmp = ft_itoa(s->chp[2].tmp[0]);
	mlx_string_put(M, s->img.menu, 40, 410, black(900), "Current lives : ");
	mlx_string_put(M, s->img.menu, 200, 410, ft_colors_mag(700), tmp);
	free(tmp);
}

static void			put_players_four(t_struck *s)
{
	char *tmp;

	mlx_string_put(M, s->img.menu, 10, 460, black(900), "Player 4 : ");
	mlx_string_put(M, s->img.menu, 120, 460, E(200), s->chp[3].name);
	mlx_string_put(M, s->img.menu, 40, 490, black(900), "Last live     : ");
	tmp = ft_itoa(s->chp[3].last_live);
	mlx_string_put(M, s->img.menu, 200, 490, E(200), tmp);
	free(tmp);
	tmp = ft_itoa(s->chp[3].tmp[0]);
	mlx_string_put(M, s->img.menu, 40, 510, black(900), "Current lives : ");
	mlx_string_put(M, s->img.menu, 200, 510, E(200), tmp);
	free(tmp);
}

void				second_window(t_struck *s)
{
	put_matrix(s);
	put_cycle(s);
	if (s->nb_chp >= 1)
		put_players_one(s);
	if (s->nb_chp >= 2)
		put_players_two(s);
	if (s->nb_chp >= 3)
		put_players_three(s);
	if (s->nb_chp >= 4)
		put_players_four(s);
}
