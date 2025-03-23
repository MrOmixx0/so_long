/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:39 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 03:43:02 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_and_collectibles(t_game *game)
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
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (game->map[height])
		height++;
	width = ft_strlen(game->map[0]);
	game->win_ptr = mlx_new_window(game->mlx_ptr, width * 32, height * 32,
			"So Long");
	if (!game->win_ptr)
		exit_game(game, "Error: Failed to create window\n");
	game->moves = 0;
	set_player_and_collectibles(game);
}
