
CC=g++
CFLAGS=-c -O3 -std=c++11
LDFLAGS=-lncurses

SOURCES=	program.cpp								\
					operator.boolean_or.cpp		\
					operator.add.cpp					\
					object.boolean.cpp				\
					object.integer.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=program


all: $(SOURCES) $(EXECUTABLE)


clean:
	rm *.o
	rm $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
