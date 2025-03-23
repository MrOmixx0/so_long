/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:39 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 08:19:51 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	scan_tile(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		game->player_x = j;
		game->player_y = i;
	}
	else if (game->map[i][j] == 'C')
		game->collectibles++;
	else if (game->map[i][j] == 'E')
	{
		game->exit_x = j;
		game->exit_y = i;
	}
}

static void	set_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectibles = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			scan_tile(game, i, j);
			j++;
		}
		i++;
	}
}

static void	load_textures(t_game *game, int *width, int *height)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm",
			width, height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/floor.xpm",
			width, height);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player.xpm", width, height);
	game->collect_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/collectible.xpm", width, height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/exit.xpm",
			width, height);
	if (!game->wall_img || !game->floor_img || !game->player_img
		|| !game->collect_img || !game->exit_img)
		exit_game(game, "Error: Failed to load textures\n");
}

void	init_game(t_game *game)
{
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = ft_strlen(game->map[0]);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * 32, game->height * 32,
			"So Long");
	if (!game->win_ptr)
		exit_game(game, "Error: Failed to create window\n");
	game->moves = 0;
	set_player(game);
	load_textures(game, &game->width, &game->height);
}
