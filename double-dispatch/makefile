
CC=g++
CFLAGS=-c -O3 -std=c++11
LDFLAGS=-lncurses

TEST_EXPRESSIONS=test.expressions

LIBRARY=	object.boolean.cpp						\
					object.integer.cpp						\
					operator.boolean_or.cpp				\
					operator.boolean_and.cpp			\
					operator.is_equal.cpp					\
					operator.is_less_than.cpp			\
					operator.is_greater_than.cpp	\
					operator.add.cpp

TEST_EXPRESSIONS_SOURCES =	$(TEST_EXPRESSIONS).cpp	\
														$(LIBRARY)

TEST_EXPRESSIONS_OBJECTS=$(TEST_EXPRESSIONS_SOURCES:.cpp=.o)


all: $(TEST_EXPRESSIONS)


clean:
	rm *.o
	rm $(TEST_EXPRESSIONS)


$(TEST_EXPRESSIONS): $(TEST_EXPRESSIONS_OBJECTS)
	$(CC) $(TEST_EXPRESSIONS_OBJECTS) $(LDFLAGS) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
