/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:51 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/11 12:25:12 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_game *game)
{
	exit_game(game, "Window closed\n");
	return (0);
}

int main(int argc, char **argv)
{
	t_game  game;

	if (argc != 2)
		exit_game(NULL, "Error: Provide a .ber map file\n");
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		exit_game(NULL, "Error: MiniLibX initialization failed\n");
	parse_map(argv[1], &game);
	init_game(&game);
	render_map(&game);
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
