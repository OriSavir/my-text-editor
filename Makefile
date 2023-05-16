
CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

text-editor: main.o
	$(CC) $(CFLAGS) -o text-editor main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp


clean:
	rm -f *.o hw5