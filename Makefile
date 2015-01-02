CC = gcc
CFLAGS = -Wall -MMD -std=c99 -Wunused-function
EXEC = bin/main
OBJECTS = main.o board.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	@mkdir -p bin
	${CC} ${CFLAGS} ${OBJECTS} -o ${EXEC} -lncurses

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
