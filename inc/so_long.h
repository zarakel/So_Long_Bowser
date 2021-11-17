#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define ERRNO0 0
# define ERRMSG0 "Error :\n The number of argument isn't equal 2\n"
# define ERRNO1 1
# define ERRMSG1 "Error :\n The number of map's lines is inferior than 2\n"
# define ERRNO2 2
# define ERRMSG2 "Error :\n The lines aren't equals\n"
# define ERRNO3 3
# define ERRMSG3 "Error :\n No 1 in the first and last lines\n"
# define ERRNO4 4
# define ERRMSG4 "Error :\n No 1 in first and last positions between lines\n"
# define ERRNO5 5
# define ERRMSG5 "Error :\n Elements required is missing\n"
# define ERREXT 6
# define ERRMSG6 "Error :\n Extension not recognized\n"
typedef struct s_map	t_map;

struct  s_map
{
	char	**total_map;
	int	max_x;
	int	max_y;
	int	P;
	int	C;
	int	E;
};

int	main();
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
