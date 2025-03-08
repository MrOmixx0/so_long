#include "mlx.h"
#include <stdlib.h>

typedef struct s_game {
    void *mlx;
    void *win;
    void *img_wall;
    void *img_player;
    void *img_collectible;
    void *img_exit;
    void *img_empty;
    char **map;
    int tile_size;
} t_game;

// Load textures
void load_textures(t_game *game)
{
    int img_width;
    int img_height;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &img_width, &img_height);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &img_width, &img_height);
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectable.xpm", &img_width, &img_height);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &img_width, &img_height);
    game->img_empty = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", &img_width, &img_height);
}

// Render the map
void render_map(t_game *game)
{
    int x, y;
    int tile_size = game->tile_size;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            void *img = game->img_empty;
            if (game->map[y][x] == '1')
                img = game->img_wall;
            else if (game->map[y][x] == 'P')
                img = game->img_player;
            else if (game->map[y][x] == 'C')
                img = game->img_collectible;
            else if (game->map[y][x] == 'E')
                img = game->img_exit;
            
            mlx_put_image_to_window(game->mlx, game->win, img, x * tile_size, y * tile_size);
            x++;
        }
        y++;
    }
}

