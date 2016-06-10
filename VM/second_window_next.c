/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_window_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 08:16:00 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 08:17:51 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"
#include "window.h"

void			put_cycle(t_struck *s)
{
	char *tmp;

	mlx_string_put(M, s->img.menu, 10, 20, black(900), "Cycle            =");
	tmp = ft_itoa(s->cycle);
	mlx_string_put(M, s->img.menu, 270, 20, E(699), tmp);
	free(tmp);
	mlx_string_put(M, s->img.menu, 50, 40, black(900), "Cycles/turn");
	mlx_string_put(M, s->img.menu, 170, 40, black(900), "=");
	tmp = ft_itoa(s->turn);
	mlx_string_put(M, s->img.menu, 280, 40, burn(999), tmp);
	free(tmp);
	mlx_string_put(M, s->img.menu, 10, 80, black(900), "Processes       =");
	tmp = ft_itoa(s->nb_proc);
	mlx_string_put(M, s->img.menu, 270, 80, E(699), tmp);
	mlx_string_put(M, s->img.menu, 20, 740, black(900), "Cycles_to_die");
	mlx_string_put(M, s->img.menu, 170, 740, black(900), "=");
	free(tmp);
	tmp = ft_itoa(s->img.cycle_to_die);
	mlx_string_put(M, s->img.menu, 280, 740, burn(999), tmp);
	free(tmp);
	mlx_string_put(M, s->img.menu, 20, 760, black(900), "Check   =");
	tmp = ft_itoa(s->img.check);
	mlx_string_put(M, s->img.menu, 280, 760,
		(s->img.check < 9) ? burn(999) : burn(200), tmp);
	free(tmp);
}

void			put_matrix(t_struck *s)
{
	static int	c = 0;
	static char	*tab = {AZ};
	int			i;
	int			j;
	char		tmp[41];

	j = (!c) ? -20 : -10;
	c = (c > 250) ? 1 : c + 1;
	i = 0;
	while (j < MAX)
	{
		ft_memcpy(tmp, (i < 500) ? tab + i / 20 : tab + i % 500 / 20, 41);
		if (i % (c) < 10)
			ft_strrev(tmp);
		mlx_string_put(M, s->img.menu, 0, j,
			ft_colors_mag((j > 500) ? 1000 - j : j), tmp);
		i += 41 + j;
		j += 20;
	}
}
