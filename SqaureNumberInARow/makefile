CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g
LDFLAGS=-g
LDLIBS=

SRCS=test.cpp SquareNumbersOnPath.cpp
OBJS=test.o SquareNumbersOnPath.o

all: test

test: $(OBJS)
	$(CXX) $(LDFLAGS) -o test $(OBJS) $(LDLIBS) 

test.o: test.cpp SquareNumbersOnPath.h

SquareNumbersOnPath.o: SquareNumbersOnPath.h SquareNumbersOnPath.cpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) test
