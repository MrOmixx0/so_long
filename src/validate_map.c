/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:14 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 05:38:39 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_game *game)
{
	int	i;
	int	j;

	game->p_count = 0;
	game->e_count = 0;
	game->c_count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->p_count++;
			else if (game->map[i][j] == 'E')
				game->e_count++;
			else if (game->map[i][j] == 'C')
				game->c_count++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				exit_game(game, "Error: Invalid character in map\n");
			j++;
		}
		i++;
	}
}

void	check_walls(t_game *game, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (game->map[0][i] != '1' || game->map[height - 1][i] != '1')
			exit_game(game, "Error: Map not surrounded by walls\n");
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (game->map[i][0] != '1' || game->map[i][width - 1] != '1')
			exit_game(game, "Error: Map not surrounded by walls\n");
		i++;
	}
}

static void	check_entity_counts(t_game *game)
{
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
		exit_game(game, "Error: Invalid number of P, E, or C\n");
}

void	validate_map(t_game *game)
{
	int		i;
	int		height;
	size_t	width;

	i = 0;
	while (game->map[i])
		i++;
	height = i;
	width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != width)
			exit_game(game, "Error: Map not rectangular\n");
		i++;
	}
	check_chars(game);
	check_walls(game, height, width);
	check_entity_counts(game);
}
