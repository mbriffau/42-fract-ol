# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 18:50:11 by mbriffau          #+#    #+#              #
#    Updated: 2017/10/05 00:37:59 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

CC =			gcc

FLAGS =			-Wall -Werror -Wextra

HEADER =		$(HEADER_DIR)/libft.h \
				$(HEADER_DIR)/get_next_line.h

HEADER_DIR =	./$(INC)

FT_SRC_DIR =	./$(SRCS)

INC =			includes/

SRCS = 			srcs/

FT_FILES =	ft_putchar ft_putstr ft_strlen ft_strcat ft_strncat ft_strlcat ft_strcpy ft_strncpy \
	ft_strdup ft_strndup ft_strcmp ft_strncmp ft_strstr ft_strnstr ft_strchr ft_strnchr \
	ft_strrchr ft_isalpha ft_isdigit ft_isalnum ft_isprint ft_isascii ft_tolower ft_toupper \
	ft_bzero ft_memset ft_memchr ft_memcmp ft_memcpy ft_memccpy ft_memmove ft_atoi ft_memalloc \
	ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi \
	ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_itoa ft_putendl ft_putnbr \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel ft_lstadd \
	ft_lstiter ft_lstmap ft_swap ft_iterative_factorial ft_strrev ft_count_word ft_wordlen \
	ft_double_memalloc ft_strlen_c ft_strcut ft_strnjoinfree ft_itoa_base get_next_line ft_error

FT_COMPILED =	$(addsuffix .o,$(FT_FILES))

COMPILED =		$(FT_COMPILED)

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

$(NAME): $(FT_COMPILED)
	@ar rc $(NAME) $(FT_COMPILED)
	@ranlib $(NAME)
	@echo "$(LOG_CLEAR)$(NAME) \033[0;32mcreated.\033[0m"

$(FT_COMPILED): %.o: $(FT_SRC_DIR)%.c $(HEADER)
	@echo "$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) -c $(FLAGS) -I $(HEADER_DIR) $< -o $@
	@echo "$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"

clean:
	@-/bin/rm -f $(COMPILED)

fclean:
	@-/bin/rm -f $(NAME)
	@echo "$(NAME) has been \033[1;31mdeleted\033[0m."

re: fclean all

.PHONY.: all clean fclean re