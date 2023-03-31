# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 11:19:05 by vgejno            #+#    #+#              #
#    Updated: 2023/03/31 19:50:26 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SANITIZE = -fsanitize=address 
CC = gcc
FLAGS = -Wall -Werror -Wextra
FLAGS += -g
FLAGS += ${SANITIZE}

RLIB = -L$(HOME)/.brew/opt/readline/lib -lreadline
RINC = -I$(HOME)/.brew/opt/readline/include

ifeq ($(shell echo $(USER)), mac)
	RLIB = -L/usr/local/Cellar/readline/8.2.1/lib -lreadline
	RINC = -I/usr/local/Cellar/readline/8.2.1/include
endif
LIBFT = libft/libft.a

# << HEADERS >> #
#DIR_SRCS = ./srsc
#DIR_OBJS = ./objs
DIR_INCS = ./headers/
INCS = ${DIR_INCS}/minishell.h

MAKE = make -s
RM = rm -rf

# << SOURCES >> #
DIR_SRCS = ./srcs
DIR_SRCS += ./srcs/lexer
DIR_SRCS += ./srcs/parser
DIR_SRCS += ./srcs/env
DIR_SRCS += ./srcs/built_in

SRCS = ${DIR_SRCS}/main.c
#SRCS += ${DIR_SRCS}/..

# << OBJECTS >> #
DIR_OBJS = ./objs
OBJS = ${addprefix ${DIR_OBJS}/, ${notdir ${SRCS:.c=.o}}}


SRCS =	srcs/main.c \
		srcs/env/my_envp.c \
		srcs/env/env_util.c \
		srcs/lexer/interpret.c \
		srsc/lexer/interp_delim.c \
		srcs/lexer/interp_quotes.c \
		srcs/lexer/interp_word.c \
		srcs/lexer/token.c \
		srcs/built_in/pwd.c \
		srcs/parser/parse.c \
		srcs/built_in/cd.c \
		# srcs/built_in/builtin.c \
		# srcs/parser/pt.c \
		
		

		
		

DFILES = srcs/${addprefix ${DIR_OBJS}/, ${notdir ${SRCS:.c=.d}}}

vpath %.c ${DIR_SRCS}

all: ${NAME}

${NAME}: 	${OBJS}
			${MAKE} -C libft
	${CC} ${FLAGS} ${OBJS} ${RLIB} ${LIBFT} -o ${NAME}

${DIR_OBJS}/%.o : %.c | ${DIR_OBJS}
	${CC} ${FLAGS} -I ${RINC} -I ${DIR_INCS} -o $@ -c $^ -MD
include ${wildcard *.d}	

${DIR_OBJS}:
	mkdir -p ${DIR_OBJS}

clean:
	${MAKE} clean -C libft
	${RM} ${DIR_OBJS} ${DFILES}
	
fclean: clean
	${MAKE} fclean -C libft
	${RM} ${NAME}

	
re: fclean all

.PHONY: all re clean fclean 