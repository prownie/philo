# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:51:45 by rpichon           #+#    #+#              #
#    Updated: 2020/02/29 15:57:06 by rpichon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


HEADER		=		includes/minishell.h
LIB			=		libftprintf.a
LIBS		=		lib/libftprintf.a
SRC_PATH	=		srcs
SRCS_NAME	= 		main.c dir_functions.c parsing.c disp_functions.c \
					env_functions.c env_functions2.c echo_functions.c \
					export.c redirect_functions.c export_sort.c
OBJS		= 		${SRCS:.c=.o}
NAME		= 		minishell
RM			= 		rm -f
FLAGS 		= 		-g -Wall -Wextra -Werror
#FLAGS		=		-g3 -fsanitize=address
SRCS 		= 		$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#								REGLES									       #
# **************************************************************************** #

all:							$(LIB) $(NAME) Makefile

%.o: %.c 						$(HEADER) $(LIBS)
								@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
								@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME):						$(OBJS) $(HEADER) Makefile
								@echo "\n\033[0;32m[COMPILATION CUB3D OK] \033[0m \033\n"
								@gcc $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
								@echo "\n\033[0;32m[minishell OK] \033[0m \033\n"

$(LIB):
								@$(MAKE) -C lib all

clean:
								@$(MAKE) -C lib clean
								@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing File object\033[0m"
								@$(RM) $(OBJS)

fclean:							clean
								@$(MAKE) -C lib fclean
								@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing All\033[0m\n"
								@$(RM) $(NAME)

re:								fclean all

.PHONY: 						clean fclean

