# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:51:45 by rpichon           #+#    #+#              #
#    Updated: 2021/01/08 18:18:30 by rpichon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


HEADER		=		includes/philo.h
SRC_PATH	=		srcs
SRCS_NAME	= 		error.c philosophers.c utils1.c
OBJS		= 		${SRCS:.c=.o}
NAME		= 		philo_one
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
								@echo "\n\033[0;32m[COMPILATION PHILO OK] \033[0m \033\n"
								@gcc $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
								@echo "\n\033[0;32m[philo_one OK] \033[0m \033\n"

clean:
								@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing File object\033[0m"
								@$(RM) $(OBJS)

fclean:							clean
								@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing All\033[0m\n"
								@$(RM) $(NAME)

re:								fclean all

.PHONY: 						clean fclean

