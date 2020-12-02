CC=g++
CFLAGS=-g -std=c++11 -Wall  -c
LDFLAGS=
SOURCES=game.cpp display.cpp compMove.cpp checkWin.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tictactoe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
