/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <jbuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:45:32 by juan              #+#    #+#             */
/*   Updated: 2021/11/30 17:51:06 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/macro.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

void	free_split(char **cpy_argv)
{
	char	**tmp;

	tmp = cpy_argv;
	while (*tmp)
		free(*tmp++);
	free(cpy_argv);
}

void	error_san(int error, char *error_msg)
{
	if (error == ERREXT)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO1)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO2)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO3)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO4)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO5)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO7)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO8)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO9)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO10)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO11)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO12)
		write(2, error_msg, ft_strlen(error_msg));
	exit(0);
}

void	print_moves(t_map *map)
{
	map->moves++;
	ft_putstr_fd("Moves : ", 1);
	ft_putnbr_fd(map->moves, 1);
	ft_putstr_fd(" \n", 1);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->total_map[i])
	{
		write(1, map->total_map[i], map->max_x + 1);
		write(1, "\n", 2);
		i++;
	}
}

int	ciao(t_map *map)
{
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	map->vars.win = 0;
	free_split(map->total_map);
	write(1, "Ciao !\n", 9);
	while (1)
		;
	exit(0);
}
