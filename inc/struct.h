#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_vars t_vars;

struct	s_vars
{
	void	*mlx;
	void	*win;
};

typedef struct s_data	t_data;

struct	s_data 
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
};

typedef struct s_map	t_map;

struct  s_map
{
	t_data	img;
	t_vars	vars;
	char	**total_map;
	int	max_x;
	int	max_y;
	int	P;
	int	C;
	int	E;
};

//Déclarer une structure globale, potentiellement s_map, qui contiendrait toutes les autres structures afin de contenir les données intéressantes qui seront utilisés dans le code

#endif
