/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:48:08 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/23 03:42:29 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "stdlib.h"
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
}	t_game;

void	parse_map(char *file, t_game *game);
void	init_game(t_game *game);
void	render_map(t_game *game);
int		handle_key(int keycode, t_game *game);
void	exit_game(t_game *game, char *msg);
void	validate_map(t_game *game);
void	check_path(t_game *game);
void	check_extension(char *file);

#endif
