SRCS	= ft_helloworld.s \
		ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \

OBJS	= ${SRCS:=.o}

TESTSRCS = main.c \
	logutil/logutil.c \
	ft_strlen.c \
	ft_strcpy.c \
	ft_strcmp.c \

TESTOBJS = ${TESTSRCS:=.o}

NAME	= libasm.a
TEST	= test.out

OS		= $(shell uname)

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

test: ${TEST}
${TEST}: ${NAME} ${TESTOBJS}
	${CC} -o ${TEST} ${TESTOBJS} ${CFLAGS} ${LIBFLAGS}

%.s.o: %.s
	nasm -o $@ $< -f elf64

%.c.o: %.c
	${CC} -c -o $@ $< ${CFLAGS}

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
