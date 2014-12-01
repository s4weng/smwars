CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = temp.o game.o headers.o GameObjectManager.o GameObject.o character.o player.o AIChar.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = temp
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} ${LIBS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}