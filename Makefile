NAME = push_swap
LIBNAME = libpushswap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Main files
files = input_check/parce \
		input_check/doubles_check push_swap \
		operations/push \
		operations/reverse_rotate \
		operations/rotate \
		operations/swap \
		logic/range \
		helper_funcs/get_node \
		minimals/cinq minimals/quatre minimals/trois \

# Bonus files
bfiles = Bonus/checker_bonus \
		 Bonus/get_input_bonus/get_input_bonus \
		 Bonus/gnl_bonus/get_next_line_bonus \
		 Bonus/gnl_bonus/get_next_line_utils_bonus \
		 Bonus/helper_funcs_bonus/get_node_bonus \
		 Bonus/input_check_bonus/doubles_check_bonus \
		 Bonus/input_check_bonus/parce_bonus \
		 Bonus/logic_bonus/range_bonus \
		 Bonus/minimals_bonus/cinq_bonus \
		 Bonus/minimals_bonus/quatre_bonus \
		 Bonus/minimals_bonus/trois_bonus \
		 Bonus/operations_bonus/push_bonus \
		 Bonus/operations_bonus/reverse_rotate_bonus \
		 Bonus/operations_bonus/rotate_bonus \
		 Bonus/operations_bonus/swap_bonus \

CFILES = $(files:%=%.c)
OBJS = $(files:%=%.o)

BONUS_CFILES = $(bfiles:%=%.c)
BONUS_OBJS = $(bfiles:%=%.o)

LIBFT_DIR = utils/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

$(LIBNAME): $(OBJS)
	ar crs $@ $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus rule
bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o checker $(BONUS_OBJS) $(LIBFT)

# Rule to build libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(LIBNAME) checker
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus