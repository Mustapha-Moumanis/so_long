NAME = so_long

FILES = so_long.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_strnstr.c\
		ft_substr.c ft_strtrim.c get_next_line.c get_next_line_utils.c ft_strrchr.c \
		check_map.c check_file_format.c function_utils.c

FILES := $(addprefix src/, $(FILES))

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(FILES)
	cc $(FLAGS) $(FILES) $(MLX) -o $(NAME)

debug:
	cc $(FLAGS) -fsanitize=address -g $(FILES) $(MLX) -o $(NAME) 

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all