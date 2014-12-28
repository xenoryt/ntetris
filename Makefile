CC = gcc
CFLAGS = -Wall -MMD
EXEC = bin/main
OBJECTS = main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	@mkdir -p bin
	${CC} ${CFLAGS} ${OBJECTS} -o ${EXEC} -lncurses

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
