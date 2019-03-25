NAME = fdf

all: $(NAME)

SRCS = src/*.c

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

$(NAME):
	make -C libft
	gcc -I /usr/local/Include $(SRCS) $(LIBFT) -o $(NAME) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit	

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
