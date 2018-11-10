NAME = ft_ls
LIBFT = libft/libft.a

INC = -I libft/includes -I ./includes
SRC = $(addprefix srcs/, error.c render_utils.c render.c btree.c opts.c file.c ls_dir.c ls.c main.c)
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

all: $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
