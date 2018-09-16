NAME = b_ls

SRC = b_ls.c\
	btree.c\
	error.c\
	get_opts.c\
	render.c\
	main.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) libft/libft.a
	gcc -Wall -Werror -Wextra $(OBJ) libft/libft.a -o $(NAME)

libft/libft.a:
	cd libft && make && make clean

%.o: %.c
	gcc -Wall -Wextra -Wall -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean $(NAME)
