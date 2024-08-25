Name = philo
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
	  utils.c \
	  ft_init.c \
	  ft_routine.c \
	  ft_helpers.c \
	  ft_free_data.c \

RM = rm -f

obj = $(SRC:.c=.o)

all: $(Name)

$(Name): $(obj)
	$(CC) $(CFLAGS) -o $(Name) $(obj)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(Name)

re: fclean all

.PHONY: all clean fclean re
