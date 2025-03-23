/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:29:01 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 04:36:54 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_img, j
			* 32, i * 32);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_img, j
			* 32, i * 32);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img,
			j * 32, i * 32);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collect_img,
			j * 32, i * 32);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_img, j
			* 32, i * 32);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			render_tile(game, i, j);
			j++;
		}
		i++;
	}
}
