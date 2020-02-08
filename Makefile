# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/29 20:11:21 by nben-haj          #+#    #+#              #
#    Updated: 2017/10/05 00:40:31 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = ./libft/

SRCS = srcs/main.c \
		srcs/algorythms.c \
		srcs/julia.c \
		srcs/event.c \
		srcs/color.c \
		srcs/event_mouse.c

FLAGS = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# **************************************************************************** #
# RULES

all: $(NAME)

$(NAME):
	@echo "$(LOG_CLEAR)$(LOG_VIOLET)project $(NAME) ==> 25% compliled..........$(LOG_YELLOW)$(LOG_NOCOLOR)$(LOG_UP)            "
	@make -C $(SRC_PATH)
	@echo "$(LOG_CLEAR)$(LOG_VIOLET)project $(NAME) ==> 50% compliled..........$(LOG_YELLOW)$(LOG_NOCOLOR)$(LOG_UP)            "
	@gcc  -o $(NAME) $(FLAGS) minilibx_macos/libmlx.a ./libft/libft.a $(SRCS)
	@echo "$(LOG_CLEAR)$(LOG_VIOLET)project $(NAME) ==> 75% compliled..........$(LOG_YELLOW)$(LOG_NOCOLOR)$(LOG_UP)            "
	@gcc  -o $(NAME) $(FLAGS) minilibx_macos/libmlx.a ./libft/libft.a $(SRCS)
	@echo "$(LOG_CLEAR)$(LOG_VIOLET)project $(NAME) ==> 100% compliled$(LOG_YELLOW)$(LOG_NOCOLOR)$            "
	@echo "$(LOG_CLEAR)$(LOG_GREEN)$(NAME) Created."


clean:
	@make clean -C $(SRC_PATH)
	@echo "$(LOG_CLEAR)$(NAME) $(LOG_RED)Cleaned."

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f ./libft/libft.a

re: fclean all

.PHONY : all, $(NAME), clean, fclean, re