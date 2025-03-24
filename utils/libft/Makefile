# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 17:21:43 by moel-idr          #+#    #+#              #
#    Updated: 2025/03/24 15:14:02 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

files = ft_strlen \
        ft_memmove \
        ft_memcpy \
        ft_strlcpy \
        ft_strlcat \
        ft_isalpha \
        ft_isdigit \
        ft_isalnum \
        ft_isascii \
        ft_isprint \
        ft_memset \
        ft_bzero \
        ft_toupper \
        ft_tolower \
        ft_strchr \
        ft_strrchr \
        ft_strncmp \
        ft_memchr \
        ft_memcmp \
        ft_strnstr \
        ft_atoi \
        ft_calloc \
        ft_strdup \
        ft_substr \
        ft_strjoin \
        ft_strtrim \
        ft_split \
        ft_itoa \
        ft_strmapi \
        ft_striteri \
        ft_putchar_fd \
        ft_putstr_fd \
        ft_putendl_fd \
        ft_putnbr_fd

bonus = ft_lstnew_bonus \
        ft_lstadd_front_bonus \
        ft_lstsize_bonus \
        ft_lstlast_bonus \
        ft_lstadd_back_bonus \
        ft_lstdelone_bonus \
        ft_lstclear_bonus \
        ft_lstiter_bonus 
        
Compiler = cc
Flags = -Wall -Wextra -Werror

CFILES = $(files:%=%.c) $(bonus:%=%.c)
OBJS = $(files:%=%.o) $(bonus:%=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(Compiler) $(Flags) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
