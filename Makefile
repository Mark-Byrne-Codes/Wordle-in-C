NAME = wordle

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = wordle.c file.c input.c check_word.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re