/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:12:12 by pepi              #+#    #+#             */
/*   Updated: 2024/01/23 17:55:04 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	right_move_ex(t_complete	*game, int i, int j)
{
	game->map[j][i] = 'P';
	game->x_axis = i;
	game->y_axis = j;
	game->counter++;
}

void	display_score(t_complete	*game)
{
	char	*tmp1;
	char	*itoa_tmp;

	tmp1 = " moves";
	itoa_tmp = ft_itoa(game->counter);
	if (!itoa_tmp)
		return ;
	tmp1 = ft_strjoin(itoa_tmp, tmp1);
	if (!tmp1)
		return ;
	mlx_string_put(game->mlxpointer, game->winpointer, 50, 50, 0x00ffff,
		tmp1);
}

void	display_collectables(t_complete	*game)
{
	char	*tmp1;
	char	*itoa_tmp;

	tmp1 = " collectables remaining";
	itoa_tmp = ft_itoa(game->collectables);
	if (!itoa_tmp)
		return ;
	tmp1 = ft_strjoin(itoa_tmp, tmp1);
	if (!tmp1)
		return ;
	mlx_string_put(game->mlxpointer, game->winpointer, 50, 70, 0x00ffff,
		tmp1);
}
