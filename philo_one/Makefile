# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:51:45 by rpichon           #+#    #+#              #
#    Updated: 2021/02/22 16:27:56 by root             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


HEADER		=		includes/
SRC_PATH	=		srcs
SRCS_NAME	= 		error.c philosophers.c utils1.c init.c sleep.c status.c
OBJS		= 		${SRCS:.c=.o}
NAME		= 		philo_one
RM			= 		rm -f
FLAGS 		= 		-Wall -Wextra -Werror
#FLAGS		=		-g3 -fsanitize=address -Wall -Wextra -Werror -pthread
SRCS 		= 		$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#								REGLES									       #
# **************************************************************************** #

all:							$(NAME)

%.o: %.c 						$(HEADER)
								@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
								@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME):						$(OBJS) $(HEADER) Makefile
								@echo "\n\033[0;32m[COMPILATION PHILO OK] \033[0m \033\n"
								@gcc $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
								@echo "\n\033[0;32m[philo_one OK] \033[0m \033\n"

clean:
								@echo "\033[0;32m[OK] \033[0m \033[0;33m Object files deleted:\033[0m"
								@$(RM) $(OBJS)

fclean:							clean
								@echo "\033[0;32m[OK] \033[0m \033[0;33m Object files  + exedeleted:\033[0m"
								@$(RM) $(NAME)

re:								fclean all

.PHONY: 						clean fclean

