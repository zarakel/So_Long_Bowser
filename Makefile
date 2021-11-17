CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

MY_CPPFLAGS = -I$(LIBPATH) -I$(LIBFTDIR) -I$(MLXDIR) -I$(GNLDIR)

CPPFLAGS = $(MY_CPPFLAGS)

NAME = so_long

SRCDIR = ./srcs

SRC = $(wildcard $(SRCDIR)/*.c)

LIBPATH = ./lib

GNLDIR = $(LIBPATH)/GNL
APGNL = $(GNLDIR)/get_next_line.a

LIBFTDIR = $(LIBPATH)/libft
APLIBFT = $(LIBFTDIR)/libft.a

MLXDIR = $(LIBPATH)/mlx
APMLX = $(MLXDIR)/libmlx.a

OBJ = $(SRC:.c=.o)

LDLIBS = $(APGNL) $(APLIBFT) $(APMLX) -framework OpenGL -framework AppKit

all:
	@$(MAKE) -j $(NAME)	

$(NAME): $(SRC)
	@$(MAKE) -j -s --no-print-directory -C lib/libft/
	@$(MAKE) -j -s --no-print-directory -C lib/gnl/
	@$(MAKE) -j -s --no-print-directory -C lib/mlx/
	$(CC) $(LDLIBS) $(CFLAGS) $(SRC) $(APLIBFT) $(APGNL) $(APMLX) -o $(NAME)

%.o : %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $(SRC) $< -o $@ 

clean:
	@$(MAKE) -j -s --no-print-directory -C lib/libft/ clean
	@$(MAKE) -j -s --no-print-directory -C lib/gnl/ clean 
	@$(MAKE) -j -s --no-print-directory -C lib/mlx/ clean
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -j -s --no-print-directory -C lib/libft/ fclean
	@$(MAKE) -j -s --no-print-directory -C lib/gnl/ fclean
	@$(MAKE) -j -s --no-print-directory -C lib/mlx/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: so_long all clean fclean re
