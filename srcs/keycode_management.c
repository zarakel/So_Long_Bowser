#include "../inc/so_long.h"
#include "../inc/struct.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include "../lib/GNL/get_next_line.h"
#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"
#include <stdio.h>

int	keycode_management(int keycode, t_map *map)
{
	static int	moves;
	int	old_P_y;
	//int	testos;

	//iitestos = 0;
	if (keycode == UP || keycode == LEFT || keycode == DOWN
		|| keycode == RIGHT || keycode == ESC)
	{
		if (keycode == UP) // tout les mvmts seront + ou - similaire
		{
			//iiprintf("%d", testos);
			//testos++;
			if (map->total_map[map->P_x][map->P_y - 1] == '0' 
					|| map->total_map[map->P_x][map->P_y - 1] == 'C')
			{
				old_P_y = map->P_y;
				moves++;
				ft_putstr_fd("Moves : ", 1);
				ft_putnbr_fd(moves, 1);
				ft_putstr_fd(" \n", 1);
				map->total_map[map->P_x][map->P_y - 1] = 'P';
				map->total_map[map->P_x][old_P_y] = '0';
			}
			else if (map->total_map[map->P_x][map->P_y - 1] == 'E' 
					&& map->C == 0)
			{
				old_P_y = map->P_y;
				ft_putnbr_fd(moves, 1);
				map->total_map[map->P_x][map->P_y - 1] = 'P';
				map->total_map[map->P_x][old_P_y] = '0';
				mlx_destroy_window(map->vars.mlx, map->vars.win);
				map->vars.win = 0;
				write(1, "Level Completed !\n", 19);
				exit(0);
			}
		}
		if (keycode == ESC)
		{
			mlx_destroy_window(map->vars.mlx, map->vars.win);
			map->vars.win = 0;
			write(1, "ESC have been used\n", 20);
			exit(0);
		}
	}
	return (0);
}
