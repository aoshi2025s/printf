# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 02:51:55 by yoaoki            #+#    #+#              #
#    Updated: 2024/05/03 00:30:20 by yoaoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NORMAL = src/ft_printf.c\
	   src/ft_put_convert.c\
	   src/ft_print_char.c\
	   src/ft_print_str.c\
	   src/ft_print_percent.c\
	   src/ft_print_int.c\
	   src/ft_numlen.c\

BONUS = $(SRCS_NORMAL)

OBJS_NORMAL = $(SRCS_NORMAL:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

INCLUDES = include

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

ifdef WITH_BONUS
	OBJS = $(OBJS_BONUS)
else
	OBJS = $(OBJS_NORMAL)
endif

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

$(NAME): $(LIBFT) $(OBJS) 
	@make -C $(LIBFT_PATH) all
	cp $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: ${NAME}

bonus: 
	@make WITH_BONUS=1 $(NAME)

clean:
	$(RM) $(OBJS_NORMAL) $(OBJS_BONUS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
