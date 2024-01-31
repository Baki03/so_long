NAME = so_long

LIBFTDIR = libft/

MLXDIR = minilibx/

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	game_logic/controls.c \
		game_logic/errors.c \
		game_logic/graphics.c \
		game_logic/map_acces.c \
		game_logic/map.c \
		game_logic/so_long.c \
		game_logic/utils_ex.c \
		game_logic/utils.c


OBJ = ${SRC:.c=.o}
INLIBFT = -L./libft -lft
INMLX = -Lminilibx -lmlx

.c.o:
	${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)
	${CC} ${OBJ} ${INLIBFT} ${INMLX} -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re