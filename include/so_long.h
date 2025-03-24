/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:48:08 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/24 06:21:07 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "stdlib.h"
# include "unistd.h"
# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	int		exit_x;
	int		exit_y;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	int		e_count;
	int		p_count;
	int		c_count;
	int		height;
	int		width;
}	t_game;

void	parse_map(char *file, t_game *game);
void	init_game(t_game *game);
void	set_player(t_game *game);
void	render_map(t_game *game);
int		handle_key(int keycode, t_game *game);
void	exit_game(t_game *game, char *msg);
void	validate_map(t_game *game);
int		close_window(t_game *game);
void	check_path(t_game *game);
void	check_extension(char *file);
void	free_map(char **map);

#endif
