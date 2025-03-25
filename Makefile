NAME = push_swap
LIBNAME = libpushswap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# Source files
files = input_check/parce \
		input_check/doubles_check push_swap \
		operations/push \
		operations/reverse_rotate \
		operations/rotate \
		operations/swap \
		logic/range \
		helper_funcs/get_node \
		minimals/cinq minimals/quatre minimals/trois \

CFILES = $(files:%=%.c)
OBJS = $(files:%=%.o)

# Libft path
LIBFT_DIR = utils/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

$(LIBNAME): $(OBJS)
	ar crs $@ $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(LIBNAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re