/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:45 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/11 12:40:36 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_player(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] != '1')
    {
        if (game->map[new_y][new_x] == 'C')
            game->collectibles--;
        else if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
            exit_game(game, "You won!\n");
        game->map[game->player_y][game->player_x] = '0';
        game->map[new_y][new_x] = 'P';
        game->player_x = new_x;
        game->player_y = new_y;
        game->moves++;
		ft_printf("Moves: %i\n", game->moves);
        render_map(game);
    }
	else
		ft_printf("Blocked or out of bounds\n");
}

int handle_key(int keycode, t_game *game)
{
	ft_printf("Key pressed : %i\n", keycode);
    if (keycode == 65307)  // ESC
        exit_game(game, "Game closed\n");
    else if (keycode == 119 || keycode == 87)  // W
        move_player(game, game->player_x, game->player_y - 1);
    else if (keycode == 115 || keycode == 83)  // S
        move_player(game, game->player_x, game->player_y + 1);
    else if (keycode == 97 || keycode == 65)   // A
        move_player(game, game->player_x - 1, game->player_y);
    else if (keycode == 100 || keycode == 68)  // D
        move_player(game, game->player_x + 1, game->player_y);
    return (0);
}
