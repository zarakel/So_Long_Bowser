/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:50:26 by juan              #+#    #+#             */
/*   Updated: 2021/11/24 18:51:44 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vars	t_vars;

struct	s_vars
{
	void	*mlx;
	void	*win;
};

typedef struct s_img	t_img;

struct	s_img
{
	void	*img;
	int		img_size;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

typedef struct s_map	t_map;

struct s_map
{
	t_img	img;
	t_vars	vars;
	char	**total_map;
	int		moves;
	int		max_x;
	int		max_y;
	int		win_w;
	int		win_h;
	int		p;
	int		p_y;
	int		p_x;
	int		c;
	int		e;
};

#endif
