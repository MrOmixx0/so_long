#include "so_long.h"
#include <stdlib.h>

static void free_map(char **map)
{
    int     i;

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

void    exit_game(t_game *game, char *msg)
{
    if (msg)
        write(2, msg, ft_strlen(msg));
    if (game && game->mlx_ptr && game->win_ptr)
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    if (game && game->map)
        free_map(game->map);
    exit(1);
}
