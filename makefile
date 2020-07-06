SRCS	= ft_helloworld.s \

OBJS	= ${SRCS:.s=.o}

OS		= $(shell uname)

NAME	= libasm.a
TEST	= test.out

ifeq (${OS}, Linux)
CC		= clang
else
CC		= gcc
endif
CFLAGS	= -Wall -Wextra -Werror
LIBFLAGS = \
	-L ./ -lasm \



${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

${TEST}: ${NAME}
	${CC} -o ${TEST} main.c ${CFLAGS} ${LIBFLAGS}

%.o: %.s
	nasm -o $@ $< -f elf64

all: ${NAME} ${TEST}

clean:
	rm -f *.o
	rm -f *.gch

fclean:
	rm -f *.o
	rm -f *.gch
	rm -f ${NAME}
	rm -f ${TEST}

re: fclean all

.PHONY: \
	all clean fclean re \
