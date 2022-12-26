SRCS = main.c crates.c moves.c stack.c

LIB = ../blib.c llist.a

all: 
	gcc -Wall -Werror -Wextra -g -fsanitize=address ${SRCS} ${LIB}