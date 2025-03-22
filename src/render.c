/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:29:01 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/11 04:02:40 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_textures(t_game *game, void **wall, void **floor,
		void **player, void **collect, void **exit)
{
	*wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm",
			&(int){32}, &(int){32});
	*floor = mlx_xpm_file_to_image(game->mlx_ptr, "textures/empty.xpm",
			&(int){32}, &(int){32});
	*player = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player.xpm",
			&(int){32}, &(int){32});
	*collect = mlx_xpm_file_to_image(game->mlx_ptr, "textures/collectible.xpm",
			&(int){32}, &(int){32});
	*exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/exit.xpm",
			&(int){32}, &(int){32});
	if (!*wall || !*floor || !*player || !*collect || !*exit)
		exit_game(game, "Error: Failed to load textures\n");
}

static void	draw_tile(t_game *game, char tile, int x, int y, void **imgs)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, imgs[0], x * 32, y
			* 32);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, imgs[1], x * 32, y
			* 32);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, imgs[2], x * 32, y
			* 32);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, imgs[3], x * 32, y
			* 32);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, imgs[4], x * 32, y
			* 32);
}

void	render_map(t_game *game)
{
	int		i;
	int		j;
	void	*imgs[5];

	load_textures(game, &imgs[0], &imgs[1], &imgs[2], &imgs[3], &imgs[4]);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			draw_tile(game, game->map[i][j], j, i, imgs);
			j++;
		}
		i++;
	}
}
