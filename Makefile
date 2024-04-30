# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 02:51:55 by yoaoki            #+#    #+#              #
#    Updated: 2024/05/01 02:56:35 by yoaoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

BONUS = $(SRCS)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

INCLUDES = include

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

ifdef IS_BONUS
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
	@make IS_BONUS=1 $(NAME)

clean:
	$(RM) $(OBJS_NORMAL) $(OBJS_BONUS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
