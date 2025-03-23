/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:55 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 06:29:34 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game(NULL, "Error: Cannot open map file\n");
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static void	store_map(char *file, t_game *game, int lines)
{
	int		fd;
	int		i;
	char	*line;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game(game, "Error: Cannot open map file\n");
	game->map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!game->map)
		exit_game(game, "Error: Memory allocation failed\n");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		temp = line;
		while (*temp && *temp != '\n')
			temp++;
		*temp = '\0';
		game->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

void	parse_map(char *file, t_game *game)
{
	int	lines;

	lines = count_lines(file);
	if (lines < 3)
		exit_game(NULL, "Error: Map too small\n");
	store_map(file, game, lines);
	validate_map(game);
}
