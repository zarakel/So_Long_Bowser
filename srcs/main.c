#include "../inc/so_long.h"
#include "../inc/struct.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include "../lib/GNL/get_next_line.h"
#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"
#include <stdio.h>

void	init_struct(t_map *n)
{
	n->total_map = 0;
	n->max_x = 0;
	n->max_y = 0;
	n->P = 0;
	n->C = 0;
	n->E = 0;
}

int	main(int argc, char *argv[])
{
	t_map	n;
	int	i;

	i = 0;
	if (argc != 2)
		error_san(ERRNO0, ERRMSG0);
	init_struct(&n);
	n.total_map = build_map(argv, &n);
	check_bit_by_bit(n.total_map, &n);
	while (n.total_map[i])
	{
		printf("total_map[%d] = %s\n", i, n.total_map[i]);
		i++;
	}
	free_split(n.total_map);
	cast_img(n);
	return (0);
}

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
	while (y++ != 400)
	 	my_mlx_pixel_put(&n.img, x, y, 0x00FF0000);
	mlx_hook(n.vars.win, 2, 1L<<0, keycode_management, &n.vars);	
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

int	keycode_management(int keycode, t_vars *vars)
{
	/*int	moves;
	if (keycode == UP || keycode == LEFT || keycode == DOWN
		|| keycode == RIGHT || keycode == ESC)
	{
		
		if (keycode == UP) // tout les mvmts seront + ou - similaire
		{
			if (pos_x_y-1 == 0 || C)
			{
				change_P_to_pos_x_y-1_pos;
				print_move(move);
				old_pos_x_y == 0(<- sol);
			}
			else if (pos_x_y-1 == E && n->C == 0)
			{
				change_P_to_pos_x_y-1_pos;
				print_move(move);
				mlx_destroy_window(vars->mlx, vars->win);
				vars->win = 0;
				write(1, "Level Completed !\n", 19);
				exit(0);
			}
		}*/
		if (keycode == ESC) 
		{
			mlx_destroy_window(vars->mlx, vars->win);
			vars->win = 0;
			write(1, "ESC have been used\n", 20);
			exit(0);
		}
	//}
	return (0);
}
