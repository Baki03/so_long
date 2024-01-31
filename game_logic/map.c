/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:01 by prossi            #+#    #+#             */
/*   Updated: 2024/01/31 10:24:03 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	width_of_map(char *line)
{
	int	width;

	width = 0;
	while (line[width] != '\0' && line[width] != '\n')
		width++;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**tmp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	tmp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!tmp)
		return (0);
	while (i < game->heightmap - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = ft_strdup(line);
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

int	map_reading(t_complete *game, char **argv)
{
	char	*readmap;

	readmap = NULL;
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		printf("map can not be open");
		exit (0);
	}
	readmap = get_next_line(game->fd);
	if (readmap == NULL || (!add_line(game, readmap)))
	{
		ft_printf("Error\nMap empty");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
