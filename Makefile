# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduarte- <dduarte-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 08:28:22 by dduarte-          #+#    #+#              #
#    Updated: 2024/06/28 08:28:22 by dduarte-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = checks.c init.c utils.c routine.c threads.c main.c

NAME = philo

OBJS = ${SRC:.c=.o}

RM = rm -f

FLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=thread -I include

MAKE = make -C

all: ${NAME}

${NAME}: ${OBJS}
						cc ${FLAGS} ${OBJS} -o ${NAME}
						
clean:
						${RM} ${OBJS}

fclean: clean
						${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re