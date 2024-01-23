/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_acces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:58:11 by pepi              #+#    #+#             */
/*   Updated: 2024/01/23 16:45:20 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static bool	is_move_valid(t_complete *game, int y, int x,
		int has_visited[MAX_LINES][MAX_LINES])
{
	if (game->map[y][x] == '1' || has_visited[y][x])
		return (false);
	return (true);
}

static void	flood_fill(t_complete *game, int y, int x,
		int has_visited[MAX_LINES][MAX_LINES])
{
	int					i;
	static int			direction_x[] = {-1, 0, 0, 1};
	static int			direction_y[] = {0, -1, 1, 0};
	int					new_x;
	int					new_y;

	i = 0;
	has_visited[y][x] = 1;
	while (i < 4)
	{
		new_x = x + direction_x[i];
		new_y = y + direction_y[i];
		if (is_move_valid(game, new_y, new_x, has_visited))
			flood_fill(game, new_y, new_x, has_visited);
		i++;
	}
}

static t_player	find_position(t_complete *game, char tile)
{
	t_player	pos;

	pos.y = 0;
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x])
		{
			if (game->map[pos.y][pos.x] == tile)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

void	check_map_solvable(t_complete *game)
{
	t_player		player_pos;
	static int		has_visited[MAX_LINES][MAX_LINES] = {0};
	int				x;
	int				y;

	y = 0;
	player_pos = find_position(game, 'P');
	flood_fill(game, player_pos.y, player_pos.x, has_visited);
	while (y < game->heightmap)
	{
		x = 0;
		while (x < game->widthmap)
		{
			if ((game->map[y][x] == 'C'
				|| game->map[y][x] == 'E')
				&& !has_visited[y][x])
			{
				ft_printf("ERROR\n exit or collectables unaccesible !");
				exit_point(game);
			}
			x++;
		}
		y++;
	}
}
