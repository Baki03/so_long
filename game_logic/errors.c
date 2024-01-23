/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:33:01 by prossi            #+#    #+#             */
/*   Updated: 2024/01/23 16:45:01 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	vertical_wall_check(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap - 1;
	while (height < game->heightmap)
	{
		if (game->map[height][0] != '1')
			return (0);
		else if (game->map[height][width] != '1')
			return (0);
		height++;
	}
	return (1);
}

static int	horizontal_wall_check(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
		height++;
	width = 0;
	while (width < game->widthmap)
	{
		if (game->map[0][width] != '1' || game->map[height][width] != '1')
			return (0);
		width++;
	}
	return (1);
}

void	if_walls(t_complete *game)
{
	if (horizontal_wall_check(game) != 1 || vertical_wall_check(game) != 1)
	{
		ft_printf("Error\nWalls missing Map !\n");
		exit_point(game);
	}
}

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'M' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("Error\nHere!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->collectables++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->collectables >= 1
			&& game->exitcount == 1))
	{
		printf("Error\nSomething is wrong!");
		printf("\neither player, exit or collectable issue");
		exit_point(game);
	}
}
