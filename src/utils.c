/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:29:08 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/11 12:39:47 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_game(t_game *game, char *msg)
{
	if (msg)
		ft_printf("%s", msg);
	if (game)
	{
		if (game->mlx_ptr && game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->map)
			free_map(game->map);
	}
	exit(1);
}
