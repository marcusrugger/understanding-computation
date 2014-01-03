
CC=g++
CFLAGS=-c -O3 -std=c++11
LDFLAGS=-lncurses

LIBRARY=	object.boolean.cpp						\
					object.integer.cpp						\
					operator.boolean_or.cpp				\
					operator.boolean_and.cpp			\
					operator.is_equal.cpp					\
					operator.is_less_than.cpp			\
					operator.is_greater_than.cpp	\
					operator.add.cpp							\
					operator.subtract.cpp					\
					operator.multiply.cpp


TEST_EXPRESSIONS_SIMPLE=test.expressions.simple

TEST_EXPRESSIONS_SIMPLE_SOURCES =	$(TEST_EXPRESSIONS_SIMPLE).cpp	\
																	$(LIBRARY)

TEST_EXPRESSIONS_SIMPLE_OBJECTS=$(TEST_EXPRESSIONS_SIMPLE_SOURCES:.cpp=.o)
					

TEST_EXPRESSIONS_COMPLEX=test.expressions.complex

TEST_EXPRESSIONS_COMPLEX_SOURCES =	$(TEST_EXPRESSIONS_COMPLEX).cpp	\
																		$(LIBRARY)

TEST_EXPRESSIONS_COMPLEX_OBJECTS=$(TEST_EXPRESSIONS_COMPLEX_SOURCES:.cpp=.o)


all:	$(TEST_EXPRESSIONS_SIMPLE)		\
			$(TEST_EXPRESSIONS_COMPLEX)


clean:
	rm *.o
	rm $(TEST_EXPRESSIONS_SIMPLE)
	rm $(TEST_EXPRESSIONS_COMPLEX)


$(TEST_EXPRESSIONS_SIMPLE):	$(TEST_EXPRESSIONS_SIMPLE_OBJECTS)
	$(CC) $(TEST_EXPRESSIONS_SIMPLE_OBJECTS) $(LDFLAGS) -o $@


$(TEST_EXPRESSIONS_COMPLEX):	$(TEST_EXPRESSIONS_COMPLEX_OBJECTS)
	$(CC) $(TEST_EXPRESSIONS_COMPLEX_OBJECTS) $(LDFLAGS) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
