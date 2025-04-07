/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:39 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/11 12:43:09 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void set_player_and_collectibles(t_game *game)
{
    int i = 0;
    int j;

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
            j++;
        }
        i++;
    }
}

void    init_game(t_game *game)
{
    int width;
    int height;

    height = 0;
    while (game->map[height])
        height++;
    width = ft_strlen(game->map[0]);
    game->win_ptr = mlx_new_window(game->mlx_ptr, width * 32, height * 32, "So Long");
    if (!game->win_ptr)
        exit_game(game, "Error: Failed to create window\n");
    game->moves = 0;
	set_player_and_collectibles(game);
    ft_printf("Player at (%i, %i), Collectibles: %i\n", game->player_x, game->player_y, game->collectibles);
}
