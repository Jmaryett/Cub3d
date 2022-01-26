NAME = cub3d

LIBA_C = ./libft/*.c

LIBA_H = ./libft/libft.h

LIBA = libft.a

SOURCE = main.c errors.c check_input.c \
		./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
		./parse_input/check_list_content.c ./parse_input/init_all.c \
		./parse_input/utils.c ./parse_input/valid_text_elem.c ./parse_input/check_if_all_elems_filled.c \
		./parse_input/map/check_text_struct.c ./parse_input/map/process_map.c 

OBJ = $(SOURCE:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

HEADER = cub.h \
		./libft/libft.h \
		./gnl/get_next_line.h

MLX = libmlx.dylib


.PHONY: all clean fclean re bonus norm libft minilibx

.c.o: ${HEADER}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

${MLX}:
		cd ./mlx; \
		make; \
		mv ${MLX} ../; \
		make clean; \
		cd ../

$(LIBA): $(LIBA_C) $(LIBA_H)
			cd ./libft; \
			make bonus; \
			mv $(LIBA) ../; \
			make clean; \
			cd ../

${NAME}: ${LIBA} ${MLX} ${HEADER} ${OBJ}
		${CC} ${CFLAGS} -framework  OpenGL -framework AppKit -o ${NAME} ${OBJ} ${LIBA} ${MLX}

clean:
		${RM} ${OBJ}

fclean:	clean
		${RM} ${NAME} a.out ${LIBA} ${MLX}

norm:
		norminette ${SOURCE} ${HEADER}

re:		fclean all
