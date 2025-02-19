#include <stdlib.h>
#include <..mlx/mlx.h> // in cluster pc change that to the minilibx path (ask about it)
#include <../includes/so_long.h>

int main (int ac, char *av[])
{
	void *mlx;
	void *win;

	mlx = mlx.init();
	win = mlx_new_window(mlx, 1024, 768, "so_long");

	mlx_loop(mlx);
	return (0);
}
