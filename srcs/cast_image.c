#include "../inc/so_long.h"
#include "../inc/struct.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"

int	cast_img(t_map n)
{
	int	x;
	int	y;

	x = 400;
	y = 0;
	n.vars.mlx = mlx_init();
	n.vars.win = mlx_new_window(n.vars.mlx, 800, 800, "So_Long");
	n.img.img = mlx_new_image(n.vars.mlx, 800, 800);
	n.img.addr = mlx_get_data_addr(n.img.img, &n.img.bits_per_pixel, &n.img.line_length, &n.img.endian);
	mlx_hook(n.vars.win, 2, 1L<<0, keycode_management, &n);
	while (y++ != 400)
		my_mlx_pixel_put(&n.img, x, y, 0x00FF0000);
	mlx_put_image_to_window(n.vars.mlx, n.vars.win, n.img.img, 0, 0);
	mlx_loop(n.vars.mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
