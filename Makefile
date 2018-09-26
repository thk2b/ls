NAME = b_ls

SRC =\
	lib.c\
	error.c\
	render_utils.c\
	render.c\
	btree.c\
	opts.c\
	file.c\
	b_ls_dir.c\
	b_ls.c\
	main.c\

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
