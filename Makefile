CXX = g++ -L/usr/X11R6/lib -lX11
CXXFLAGS = -Wall -MMD -O2
EXEC = life-graphical
OBJECTS = main.o cell.o grid.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	 ${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

clean:
	 rm ${OBJECTS} ${EXEC} ${DEPENDS}
