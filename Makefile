NAME = cub3d

NAME_LINUX = cub3D

LIBA_C = ./libft/*.c

LIBA_H = ./libft/libft.h

LIBA = libft.a

SOURCE = main.c errors.c check_input.c \
		./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
		./parse_input/check_list_content.c ./parse_input/init_all.c \
		./parse_input/utils.c ./parse_input/valid_text_elem.c ./parse_input/check_if_all_elems_filled.c \
		./parse_input/create_map.c \
		./parse_input/floor_ceiling_text_parse/check_text_struct.c \
		./parse_input/floor_ceiling_text_parse/check_ceiling_struct.c \
		./parse_input/floor_ceiling_text_parse/check_floor_struct.c \
		./parse_input/floor_ceiling_text_parse/utils_for_color.c \
		./parse_input/floor_ceiling_text_parse/check_ceiling_format.c \
		./parse_input/floor_ceiling_text_parse/check_floor_format.c \
		./parse_input/validate_map/check_if_map_is_valid.c ./parse_input/validate_map/check_walls.c \
		./parse_input/validate_map/check_how_map_filled.c 

OBJ = $(SOURCE:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

HEADER = cub.h \
		./libft/libft.h \
		./gnl/get_next_line.h \
		/usr/include/X11/

MLX = libmlx.dylib

MLX_LINUX = libmlx_Linux.a

.PHONY: all clean fclean re bonus norm libft minilibx

.c.o: ${HEADER}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)


${MLX}:
		cd ./mlx; \
		make; \
		mv ${MLX} ../; \
		cd ../

${MLX_LINUX}:
				cd ./mlx_linux; \
				make; \
				mv ${MLX_LINUX} ../; \
				cd ../

$(LIBA): $(LIBA_C) $(LIBA_H)
			cd ./libft; \
			make bonus; \
			mv $(LIBA) ../; \
			make clean; \
			cd ../

${NAME}: ${LIBA} ${MLX} ${HEADER} ${OBJ}
		${CC} ${CFLAGS} -framework  OpenGL -framework AppKit -o ${NAME} ${OBJ} ${LIBA} ${MLX}

$(NAME_LINUX): ${LIBA} ${MLX_LINUX} ${HEADER} ${OBJ}
			${CC} ${CFLAGS} -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_LINUX) ${OBJ} ${LIBA} ${MLX_LINUX}

liba: $(LIBA)

linux: $(NAME_LINUX)

clean:
		${RM} ${OBJ}

fclean:	clean
		${RM} ${NAME} $(NAME_LINUX) a.out ${LIBA} ${MLX} ${MLX_LINUX}

norm:
		norminette ${SOURCE} ${HEADER}

re:		fclean all
