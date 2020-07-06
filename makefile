SRCS	= main.c \

OBJS	= ${SRCS:.c=.o}

OS		= $(shell uname)

NAME	= libasm.a
TEST	= test.out

ifeq (${OS}, Linux)
CC		= clang
else
CC		= gcc
endif
CFLAGS	= -O3 -Wall -Wextra -Werror
LIBFLAGS = \
	-L ./ -lasm \



${NAME}:

${TEST}: ${NAME}
	gcc -o ${TEST} main.c ${LIBFLAGS}

all: ${NAME} ${TEST}

clean:
	rm -f *.o
	rm -f *.gch

fclean:
	rm -f *.o
	rm -f *.gch
	rm -f ${NAME}
	rm -g ${TEST}

re: fclean all

.PHONY: \
	all clean fclean re \
