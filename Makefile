NAME = b_ls

SRC = b_ls.c\
	main.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	gcc -Wall -Wextra -Wall -c $< -o $@

$(NAME): $(OBJ)
	gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME)

all:
	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
