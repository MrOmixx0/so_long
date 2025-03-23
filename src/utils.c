/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:29:08 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 04:28:44 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_images(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx_ptr, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx_ptr, game->player_img);
	if (game->collect_img)
		mlx_destroy_image(game->mlx_ptr, game->collect_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx_ptr, game->exit_img);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	close_window(t_game *game)
{
	exit_game(game, "Game closed\n");
	return (0);
}

void	exit_game(t_game *game, char *msg)
{
	if (msg)
		ft_printf("%s", msg);
	if (game)
	{
		if (game->mlx_ptr && game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
		{
			free_images(game);
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
		if (game->map)
			free_map(game->map);
	}
	exit(1);
}
