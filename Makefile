
CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

text-editor: main.o text_editor.o
	$(CC) $(CFLAGS) -o text-editor main.o text_editor.o

main.o: main.cpp text_editor.h
	$(CC) $(CFLAGS) -c main.cpp

text_editor.o: text_editor.cpp text_editor.h
	$(CC) $(CFLAGS) -c text_editor.cpp

clean:
	rm -f *.o hw5