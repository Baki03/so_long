/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:06:51 by prossi            #+#    #+#             */
/*   Updated: 2024/01/24 12:24:55 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	int	i;
	int	j;

	if (game->command == 13)
		game->player = mlx_xpm_file_to_image(game->mlxpointer,
				"game_images/player/bas.xpm", &i, &j);
	else if (game->command == 1)
		game->player = mlx_xpm_file_to_image(game->mlxpointer,
				"game_images/player/haut.xpm", &i, &j);
	else if (game->command == 2)
		game->player = mlx_xpm_file_to_image(game->mlxpointer,
				"game_images/player/droite.xpm", &i, &j);
	else if (game->command == 0)
		game->player = mlx_xpm_file_to_image(game->mlxpointer,
				"game_images/player/gauche.xpm", &i, &j);
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 64, height * 64);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->ennemy = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/ennemy.xpm", &i, &j);
	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player/bas.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/exitclose.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/item.xpm", &i, &j);
}

static void	adding_graphics_ext(t_complete *game, int height,
	int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->wall, width * 64, height * 64);
	else if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, width * 64, height * 64);
	else
	{
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, width * 64, height * 64);
		if (game->map[height][width] == 'C')
		{
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->collectable, width * 64, height * 64);
			game->collectables++;
		}
		if (game->map[height][width] == 'P')
			place_player(game, height, width);
		if (game->map[height][width] == 'M')
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->ennemy, width * 64, height * 64);
	}
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			adding_graphics_ext(game, height, width);
			width++;
		}
		height++;
	}
}
