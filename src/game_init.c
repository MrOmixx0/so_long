/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:39 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/11 03:39:59 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    game->collectibles = 0;  // Placeholder; update later
    game->player_x = 0;      // Placeholder; update later
    game->player_y = 0;
}
