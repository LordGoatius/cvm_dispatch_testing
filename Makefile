C_SOURCE = $(wildcard *.c)
C_HEADER = $(wildcard *.h)

OBJ = ${C_SOURCE:.c=.o}
CC = clang
CFLAGS = -O3 -std=c23

all: main

main: ${OBJ}
	${CC} ${CFLAGS} $^ -o $@

%.o: %.c ${C_HEADER}
	${CC} ${CFLAGS} -c $< -o $@

run: main
	./main

clean:
	rm ${OBJ} main
