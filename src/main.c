/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:51 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/24 06:24:40 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *file)
{
	int		len;
	char	*basename;

	len = ft_strlen(file);
	basename = file;
	while (len > 0 && file[len - 1] != '/')
		len--;
	if (len > 0 && file[len - 1] == '/')
		basename = file + len;
	len = ft_strlen(basename);
	if (len < 5 || basename[0] == '.' || ft_strncmp(basename + len - 4, ".ber",
			4) != 0)
		exit_game(NULL, "Error: File must have a valid .ber extension\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		exit_game(NULL, "Error: Provide a .ber map file\n");
	check_extension(argv[1]);
	parse_map(argv[1], &game);
	set_player(&game);
	check_path(&game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		exit_game(NULL, "Error: MiniLibX initialization failed\n");
	init_game(&game);
	render_map(&game);
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
