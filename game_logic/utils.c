/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:32:27 by pepi              #+#    #+#             */
/*   Updated: 2024/01/17 15:16:55 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_filename(const char *file)
{
	const char	*point;

	if (!file)
		exit (EXIT_FAILURE);
	point = ft_strrchr(file, '.');
	if (point == NULL || ft_strcmp(point, ".ber") != 0)
	{
		ft_printf("Erreur : Le fichier doit avoir l'extension .ber\n");
		exit(EXIT_FAILURE);
	}
}

static	void	check_map_rectangular(t_complete *game)
{
	int	width;
	int	height;

	width = 0;
	height = 1;
	while (height < game->heightmap)
	{
		width = width_of_map(game->map[height]);
		{
			if (width != game->widthmap)
			{
				ft_printf("Map not rectangular");
				exit_point(game);
			}
		}
		height++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			t = ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		t = ((char *)&s[i]);
	return (t);
}

void	check_errors(t_complete *game)
{
	check_map_rectangular(game);
	if_walls(game);
	character_valid(game);
	check_map_solvable(game);
}
