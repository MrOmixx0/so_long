/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:51 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 08:17:50 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extention(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
		exit_game(NULL, "Error: File must have .ber extension\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_game(NULL, "Error: Provide a .ber map file\n");
	check_extention(argv[1]);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		exit_game(NULL, "Error: MiniLibX initialization failed\n");
	parse_map(argv[1], &game);
	init_game(&game);
	check_path(&game);
	render_map(&game);
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
