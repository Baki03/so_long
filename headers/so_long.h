/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2024/01/17 15:17:06 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "../minilibx/mlx.h"

# define MAX_LINES 250

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game_data
{
	int			fd;
	int			heightmap;
	int			widthmap;
	int			playercount;
	int			columncount;
	int			exitcount;
	int			x_axis;
	int			y_axis;
	int			counter;
	int			collectables;
	int			command;

	char		**map;

	void		*floor;
	void		*ennemy;
	void		*wall;
	void		*player;
	t_player	player_pos;
	void		*exit;
	void		*collectable;
	void		*mlxpointer;
	void		*winpointer;

}	t_complete;

int		exit_point(t_complete *game);
int		map_reading(t_complete *game, char **argv);
int		controls_working(int command, t_complete *game);
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
void	check_errors(t_complete *game);
void	if_walls(t_complete *game);
void	character_valid(t_complete *game);
void	check_filename(const char *file);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
int		width_of_map(char *line);
void	check_map_solvable(t_complete *game);
void	right_move_ex(t_complete	*game, int i, int j);
#endif
