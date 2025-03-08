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

void load_textures(t_game *game);
void render_map(t_game *game);

// Load the map and render it
int main()
{
    t_game game;

    // Initialize MiniLibX
    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);

    // Set tile size
    game.tile_size = 32;

    // Create window (adjust width & height based on map size)
    game.win = mlx_new_window(game.mlx, 11 * 32, 7 * 32, "so_long");
    if (!game.win)
        return (1);

    // Load textures
    load_textures(&game);

    // Temporary test map (replace with actual map parsing later)
    char *test_map[] = {
        "11111111111",
        "1P0C00100C1",
        "11111010101",
        "100C1010101",
        "10001010101",
		"100000000E1",
		"11111111111",
        NULL
    };
    game.map = test_map;

    // Render the map
    render_map(&game);

    mlx_loop(game.mlx);
    return (0);
}

