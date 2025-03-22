/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 04:31:54 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/22 04:36:51 by mel-hajj         ###   ########.fr       */
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
		exit_game(NULL, "Error: Memory allocation failed\n");
	while (i < height)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
			exit_game(NULL, "Error: Memory allocation failed\n");
		i++;
	}
	dup[height] = NULL;
	return (dup);
}

static void	flood_fill(char **map, int x, int y, int *collectibles,
		char stop_at)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == stop_at || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		(*collectibles)--;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, collectibles, stop_at);
	flood_fill(map, x - 1, y, collectibles, stop_at);
	flood_fill(map, x, y + 1, collectibles, stop_at);
	flood_fill(map, x, y - 1, collectibles, stop_at);
}

void	check_path(t_game *game)
{
	char	**map_copy;
	char	**map_copy2;
	int		collectibles;
	int		i;
	int		j;
	int		exit_found;
	int		last_c_x;
	int		last_c_y;

	i = 0;
	exit_found = 0;
	last_c_x = -1;
	last_c_y = -1;
	map_copy = duplicate_map(game->map);
	collectibles = game->collectibles;
	flood_fill(map_copy, game->player_x, game->player_y, &collectibles, 'E');
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'X' && game->map[i][j] == 'C')
			{
				last_c_x = j;
				last_c_y = i;
			}
			j++;
		}
		ft_printf("After Phase 1 - Map row %i: %s\n", i, map_copy[i]);
		i++;
	}
	if (collectibles != 0 || last_c_x == -1)
	{
		while (--i >= 0)
			free(map_copy[i]);
		free(map_copy);
		exit_game(game, "Error: No valid path to win\n");
	}
	map_copy2 = duplicate_map(game->map);
	flood_fill(map_copy2, last_c_x, last_c_y, &collectibles, '1');
	i = 0;
	while (map_copy2[i])
	{
		j = 0;
		while (map_copy2[i][j])
		{
			if (map_copy2[i][j] == 'X' && game->map[i][j] == 'E')
				exit_found = 1;
			j++;
		}
		ft_printf("After Phase 2 - Map row %i: %s\n", i, map_copy2[i]);
		i++;
	}
	ft_printf("Exit found: %i\n", exit_found);
	while (--i >= 0)
		free(map_copy[i]);
	free(map_copy);
	while (--i >= 0)
		free(map_copy2[i]);
	free(map_copy2);
	if (!exit_found)
		exit_game(game, "Error: No valid path to win\n");
}
