/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:24:14 by juan              #+#    #+#             */
/*   Updated: 2021/11/30 18:13:55 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/struct.h"
#include "../inc/keycode_qwerty.h"
#include "../inc/macro.h"
#include "../lib/libft/libft.h"
#include <stdio.h>
#include <mlx.h>

int	cast_img(t_map map)
{
	map.win_w = (PIXEL * map.max_x);
	map.win_h = (PIXEL * map.max_y);
	map.vars.mlx = mlx_init();
	map.vars.win = mlx_new_window(map.vars.mlx, map.win_w,
			map.win_h, "So_Long");
	if (map.vars.mlx && map.vars.win)
	{
		mlx_hook(map.vars.win, 2, 1L << 0, keycode_management, &map);
		mlx_hook(map.vars.win, 17, 1L << 0, ciao, &map);
		print(&map);
		mlx_loop(map.vars.mlx);
		return (0);
	}
	else
		end(map.total_map, ERRNO8, ERRMSG8);
	return (1);
}
