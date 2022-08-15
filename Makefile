NAME			=	fractol
INCLUDES		=	./inc/
SRCS			=	exit.c hooks.c helpers.c image_lifecycle.c fractals.c main.c
OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror -O3
.c.o:
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o) -I ./inc -I ./mlx_linux

$(NAME):		$(OBJS)
				@make -sC ./mlx_linux all -Wno-deprecated
				@$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) -L ./mlx_linux -lmlx -framework OpenGL -framework AppKit -lz

all:			$(NAME)
clean:
				@make -sC ./mlx_linux clean
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
