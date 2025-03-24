NAME = push_swap
LIBNAME = libpushswap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
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

# bonus_files = Bonus/pipex_bonus Bonus/redirection_bonus \
#               Bonus/handle_cmd_bonus Bonus/is_cmd_a_path_bonus \
#               Bonus/get_next_line/get_next_line_bonus \
#               Bonus/get_next_line/get_next_line_utils_bonus \
# 			  Bonus/here_doc_bonus Bonus/utils_bonus

# BONUS_CFILES = $(bonus_files:%=%.c)

# BONUS_OBJS = $(bonus_files:%=%.o)

LIBFT = utils/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

# bonus: $(BONUS_OBJS) $(LIBFT)

$(LIBNAME): $(OBJS)
	ar crs $@ $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus/%.o: Bonus/%.c Bonus/pipex.h

# Bonus/get_next_line/%.o: Bonus/get_next_line/%.c Bonus/get_next_line/get_next_line.h


$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(LIBNAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re