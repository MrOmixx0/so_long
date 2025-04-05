/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 04:31:54 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 06:50:50 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**duplicate_map(char **map)
{
	int		i;
	int		height;
	char	**dup;

	i = 0;
	height = 0;
	while (map[height])
		height++;
	dup = (char **)malloc(sizeof(char *) * (height + 1));
	if (!dup)
		exit_game(NULL, "Error\n Memory allocation failed\n");
	while (i < height)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
			exit_game(NULL, "Error\n Memory allocation failed\n");
		i++;
	}
	dup[height] = NULL;
	return (dup);
}

static void	flood_fill(char **map, int x, int y, int *collectibles)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1')
		return ;
	if (map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		(*collectibles)--;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, collectibles);
	flood_fill(map, x - 1, y, collectibles);
	flood_fill(map, x, y + 1, collectibles);
	flood_fill(map, x, y - 1, collectibles);
}

static void	finalize_path(t_game *game, char **map_copy, int exit_found,
		int collectibles)
{
	int	i;

	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
	if (!exit_found || collectibles != 0)
		exit_game(game, "Error\n No valid path to win\n");
}

void	check_path(t_game *game)
{
	char	**map_copy;
	int		collectibles;
	int		i;
	int		j;
	int		exit_found;

	i = 0;
	exit_found = 0;
	map_copy = duplicate_map(game->map);
	collectibles = game->c_count;
	flood_fill(map_copy, game->player_x, game->player_y, &collectibles);
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'X' && game->map[i][j] == 'E')
				exit_found = 1;
			j++;
		}
		i++;
	}
	finalize_path(game, map_copy, exit_found, collectibles);
}
