#ifndef SO_LONG_H
# define SO_LONG_H

# include "struct.h"
# include "keycode_qwerty.h"

int	main();
int	cast_img(t_map map);
int	keycode_management(int keycode, t_vars *vars);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	free_split(char **);
void	error_san(int error, char *);
char	**build_map(char **argv, t_map *n);
void	check_bit_by_bit(char **tmp, t_map *n);
void	check_requirements(char *line_map, int y, t_map *n);
int	elements_signal(char char_map, int x, t_map *n);
char	**malloc_map_arr(char **argv, t_map *n);
char	**malloc_and_create_map_string(char **argv, t_map *n);
void	init_struct(t_map *n);

#endif
