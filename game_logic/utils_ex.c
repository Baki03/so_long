/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:12:12 by pepi              #+#    #+#             */
/*   Updated: 2024/01/17 15:14:47 by pepi             ###   ########.fr       */
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
