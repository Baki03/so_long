/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:49:02 by prossi            #+#    #+#             */
/*   Updated: 2024/01/24 12:18:53 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap - 1)
	{
		free(game->map[line]);
		line++;
	}
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;
	int			i;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	check_filename(argv[1]);
	ft_memset(&game, 0, sizeof(t_complete));
	map_reading(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 64),
			(game.heightmap * 64), "so_long");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	display_score(&game);
	display_collectables(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit_point, 0);
	mlx_loop(game.mlxpointer);
}
