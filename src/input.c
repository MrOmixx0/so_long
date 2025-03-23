/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:45 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 04:10:06 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_win(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %i\n", game->moves);
	render_map(game);
	exit_game(game, "You won!\n");
}

static void	update_position(t_game *game, int new_x, int new_y, char new_pos)
{
	if (new_pos == 'C')
		game->collectibles--;
	if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %i\n", game->moves);
	render_map(game);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	int		height;
	int		width;
	char	new_pos;

	height = 0;
	width = ft_strlen(game->map[0]);
	new_pos = game->map[new_y][new_x];
	while (game->map[height])
		height++;
	if (new_x >= 0 && new_x < width && new_y >= 0 && new_y < height
		&& new_pos != '1')
	{
		if (new_pos == 'E' && game->collectibles == 0)
			handle_win(game, new_x, new_y);
		else
			update_position(game, new_x, new_y, new_pos);
	}
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game, "Game closed\n");
	else if (keycode == 119)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == 115)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == 97)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == 100)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}
