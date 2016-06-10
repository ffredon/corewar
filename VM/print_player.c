/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 07:50:16 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 14:24:46 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"
#include "window.h"

void	print_winner_four(t_struck *s)
{
	static int	c = 0;
	int			i;
	int			ret;
	int			fd;
	char		*line;

	fd = open("VM/player/player4.txt", O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		mlx_string_put(M, W, 1200 - c, 1000 + i * 20 - c, E(200), line);
		free(line);
		line = NULL;
		++i;
	}
	close(fd);
	if (line)
		free(line);
	c = (c > 400) ? 401 : c + 4;
}

void	print_winner_three(t_struck *s)
{
	static int	c = 0;
	int			i;
	int			ret;
	int			fd;
	char		*line;

	fd = open("VM/player/player3.txt", O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		mlx_string_put(M, W, 1200 - c, 1000 + i * 20 - c, 0x00ff00, line);
		free(line);
		line = NULL;
		++i;
	}
	close(fd);
	if (line)
		free(line);
	c = (c > 400) ? 401 : c + 4;
}

void	print_winner_two(t_struck *s)
{
	static int	c = 0;
	int			i;
	int			ret;
	int			fd;
	char		*line;

	fd = open("VM/player/player2.txt", O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		mlx_string_put(M, W, 1200 - c, 1000 + i * 20 - c, I(200), line);
		free(line);
		line = NULL;
		++i;
	}
	close(fd);
	if (line)
		free(line);
	c = (c > 400) ? 401 : c + 4;
}

void	print_winner_one(t_struck *s)
{
	static int	c = 0;
	int			i;
	int			ret;
	int			fd;
	char		*line;

	fd = open("VM/player/player1.txt", O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		mlx_string_put(M, W, 1200 - c, 1000 + i * 20 - c, burn(500), line);
		free(line);
		line = NULL;
		++i;
	}
	close(fd);
	if (line)
		free(line);
	c = (c > 400) ? 401 : c + 4;
}

void	print_winner(t_struck *s, int i)
{
	static int	c = 0;
	int			j[3];
	char		*line;

	mlx_clear_window(M, W);
	if ((j[2] = open("VM/player/winner.txt", O_RDONLY)) < 0)
		return ;
	j[0] = 0;
	line = NULL;
	while ((j[1] = get_next_line(j[2], &line)) > 0)
	{
		mlx_string_put(M, W, 10 + c, 10 + j[0]++ * 20 + c, 0xffffff, line);
		free(line);
		line = NULL;
	}
	close(j[2]);
	c = (c > 400) ? 401 : c + 4;
	if (i == 0)
		print_winner_one(s);
	else if (i == 1)
		print_winner_two(s);
	else if (i == 2)
		print_winner_three(s);
	else
		print_winner_four(s);
}
