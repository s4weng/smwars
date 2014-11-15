CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = temp.o Game.o headers.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = poke
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} ${LIBS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}