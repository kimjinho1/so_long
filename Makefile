# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhokim <jinhokim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 21:05:01 by jinhokim          #+#    #+#              #
#    Updated: 2022/10/25 02:56:46 by jinhokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

SRCS			= ./mandatory/main.c \
				  ./mandatory/gnl.c \
				  ./mandatory/gnl_utils.c \
				  ./mandatory/parsing.c \
				  ./mandatory/utils.c \
				  ./mandatory/draw.c \
				  ./mandatory/move.c \

BONUS_SRCS		= ./bonus/main_bonus.c \
				  ./bonus/init_bonus.c \
				  ./bonus/gnl_bonus.c \
				  ./bonus/gnl_utils_bonus.c \
				  ./bonus/parsing_bonus.c \
				  ./bonus/utils_bonus.c \
				  ./bonus/utils_bonus2.c \
				  ./bonus/draw_bonus.c \
				  ./bonus/move_bonus.c \
				  ./bonus/enemy_bonus.c \

HEADER			= ./mandatory/so_long.h

BONUS_HEADER	= ./bonus/so_long_bonus.h

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS		= -L./mlx -lmlx -framework OpenGL -framework Appkit
RM				= rm -f

OBJS			= $(SRCS:.c=.o)

BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

$(NAME):		$(OBJS) $(HEADER)
					@$(CC) $(SRCS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

bonus:			$(BONUS_OBJS) $(BONUS_HEADER)
					@$(CC) $(BONUS_SRCS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)


all:			$(NAME)

clean:
				@$(RM) $(OBJS)
				@$(RM) $(BONUS_OBJS)

fclean:			clean
					@$(RM) $(NAME)

re:				fclean all

.PHONY:			bonus all clean fclean re
