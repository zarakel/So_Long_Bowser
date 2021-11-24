/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:43:00 by juan              #+#    #+#             */
/*   Updated: 2021/11/24 18:57:37 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"	
#include "../inc/struct.h"	
#include "../inc/macro.h"	
#include "../lib/GNL/get_next_line.h"
#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"

char	**build_map(char **argv, t_map *n)
{
	char	**tmp;
	int		size;

	size = ft_strlen(argv[1]);
	tmp = NULL;
	if (size >= 4)
	{
		if (!ft_strnstr(argv[1] + size - 4, ".ber", 4))
			error_san(ERREXT, ERRMSG6);
		tmp = malloc_and_create_map_string(argv, n);
	}
	return (tmp);
}

void	check_bit_by_bit(char **total_map, t_map *n)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	n->max_x = ft_strlen(total_map[x]);
	if (n->max_y < 2)
	{
		free_split(n->total_map);
		error_san(ERRNO1, ERRMSG1);
	}
	while (total_map[y])
	{
		check_requirements(total_map[y], y, n);
		y++;
	}
	if (n->p < 1 || n->c < 1 || n->e < 1)
	{
		free_split(n->total_map);
		error_san(ERRNO5, ERRMSG5);
	}
	return ;
}

void	check_requirements(char *line_map, int y, t_map *n)
{
	int	x;

	x = 0;
	while (line_map[x])
	{	
		if ((int)ft_strlen(line_map) != n->max_x)
		{
			free_split(n->total_map);
			error_san(ERRNO2, ERRMSG2);
		}
		if (y == 0 || y == n->max_y)
		{
			if (line_map[x] != '1')
			{
				free_split(n->total_map);
				error_san(ERRNO3, ERRMSG3);
			}
		}
		else
			elements_signal(line_map[x], x, y, n);
		x++;
	}
}

int	elements_signal(char char_map, int x, int y, t_map *n)
{
	if (x == 0 || x == n->max_x)
	{
		if (char_map != '1')
		{
			free_split(n->total_map);
			error_san(ERRNO4, ERRMSG4);
		}
	}	
	if (char_map == 'P')
	{
		n->p++;
		n->p_x = x;
		n->p_y = y;
		if (n->p > 1)
			error_san(ERRNO7, ERRMSG7);
	}
	if (char_map == 'C')
		n->c++;
	if (char_map == 'E')
		n->e++;
	return (0);
}
