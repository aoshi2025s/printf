# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 02:51:55 by yoaoki            #+#    #+#              #
#    Updated: 2024/05/04 05:18:55 by yoaoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/ft_printf.c\
	   src/ft_put_convert.c\
	   src/ft_print_char.c\
	   src/ft_print_str.c\
	   src/ft_print_ptr.c\
	   src/ft_print_percent.c\
	   src/ft_print_int.c\
	   src/ft_print_uint.c\
	   src/ft_print_hex.c\
	   src/ft_puthex_fd.c\
	   src/ft_putuint_fd.c\
	   src/ft_numlen.c\
	   src/ft_putptr_fd.c\


OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

INCLUDES = include

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

$(NAME): $(LIBFT) $(OBJS) 
	@make -C $(LIBFT_PATH) all
	cp $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: ${NAME}

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
