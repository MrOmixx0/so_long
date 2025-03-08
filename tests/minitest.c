#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int close_window(t_data *game) {
    (void)game;
	printf("Window closed.\n");
    exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_hook(int keycode, t_data *game)
{
	(void)game;
	(void)keycode;
	printf("KHADAMA HHHHAHAHAAHA\n");
	return 0;
}

int close(int keycode, t_data *game)
{
	 if (keycode == 99999999)
	  {
		  mlx_destroy_window(game->mlx, game->win);
		  return (0);
	  }
	 printf("Window closing triggered by key: %d\n", keycode);
	 return (999);
}

int	mouse_move(int x, int y, t_data *game)
{
	(void)game;
	printf("Mouse moved to position: (%d, %d)\n", x, y);
	return (0);
}

int render_next_frame(t_data game)

int main(void)
{
	int x,y,z;
	t_data	game;

	x=0,y=0,z=0x00FF0000;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 640, 480, "awedi");
	//mlx_hook(game.win, 2, 1L<<0, close, &game);
    mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_mouse_hook(game.win, mouse_move, &game);
	/*img.img = mlx_new_image(mlx, 480, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, x, y, z);
	mlx_put_image_to_window(mlx, mlxwin, img.img, 0, 0);*/
	mlx_loop(game.mlx);
}
