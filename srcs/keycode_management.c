/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:03:59 by juan              #+#    #+#             */
/*   Updated: 2021/11/24 18:54:44 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	old_p_y;
	int	old_p_x;

	old_p_y = 0;
	old_p_x = 0;
	if (keycode == UP || keycode == UP_ARROW || keycode == LEFT
		|| keycode == LEFT_ARROW || keycode == DOWN
		|| keycode == DOWN_ARROW || keycode == RIGHT
		|| keycode == RIGHT_ARROW || keycode == ESC)
	{
		if (keycode == UP || keycode == UP_ARROW)
			keycode_up(map, old_p_y);
		if (keycode == DOWN || keycode == DOWN_ARROW)
			keycode_down(map, old_p_y);
		if (keycode == LEFT || keycode == LEFT_ARROW)
			keycode_left(map, old_p_x);
		if (keycode == RIGHT || keycode == RIGHT_ARROW)
			keycode_right(map, old_p_x);
		if (keycode == ESC)
			keycode_esc(map);
		print(map);
	}
	return (0);
}
