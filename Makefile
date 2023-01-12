NAME = so_long


FILES = so_long.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c \
		get_next_line.c get_next_line_utils.c \

FILES := $(addprefix src/, $(FILES))

