NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
BONUS_CFLAGS = -Wall -Wextra -Werror -I..

SRCS = main.c mandatory/parsing.c \
       mandatory/listools.c mandatory/moves.c \
       mandatory/find_nums.c mandatory/utils.c \
       mandatory/ft_split.c  mandatory/list_to_arr.c \
       mandatory/chunk.c  mandatory/sorting.c 

BONUS_SRCS = bonus/checker.c bonus/utils.c \
             bonus/get_next_line.c bonus/get_next_line_utils.c \
             mandatory/parsing.c mandatory/listools.c \
             mandatory/find_nums.c  mandatory/utils.c \
             mandatory/ft_split.c mandatory/list_to_arr.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

../bonus/%.o: ../bonus/%.c
	$(CC) $(BONUS_CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
