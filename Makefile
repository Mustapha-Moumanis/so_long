NAME = so_long
BNAME = so_long_bonus

FILES = so_long.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_strnstr.c \
		ft_substr.c ft_strtrim.c get_next_line.c get_next_line_utils.c ft_strrchr.c \
		function_utils.c function_utils2.c move.c ft_itoa.c \
		check_map.c check_file_format.c check_road.c

BFILES = so_long_bonus.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_strnstr.c \
		ft_substr.c ft_strtrim.c get_next_line.c get_next_line_utils.c ft_strrchr.c ft_itoa.c \
		check_map.c check_file_format.c function_utils.c function_utils2.c move_bonus.c \
		check_road.c 

FILES := $(addprefix src/, $(FILES))

BFILES := $(addprefix src/, $(BFILES))

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(FILES)
	cc $(FLAGS) $(FILES) $(MLX) -o $(NAME)

bonus: $(BNAME)
	
$(BNAME): $(BFILES)
	cc $(FLAGS) $(BFILES) $(MLX) -o $(BNAME) 

clean:
	rm -rf $(NAME) $(BNAME)

fclean: clean

re: fclean all