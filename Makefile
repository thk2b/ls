NAME = b_ls

SRC =\
	error.c\
	get_opts.c\
	btree.c\
	file.c\
	render.c\
	b_ls.c\
	main.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) libft/libft.a
	gcc -Wall -Werror -Wextra $(OBJ) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C ./libft

%.o: %.c
	gcc -Wall -Wextra -Wall -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean $(NAME)
