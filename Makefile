
CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

SavvyText: main.o text_editor.o mem_buffer.o
	$(CC) $(CFLAGS) -o SavvyText main.o text_editor.o mem_buffer.o

main.o: main.cpp text_editor.h mem_buffer.h
	$(CC) $(CFLAGS) -c main.cpp

text_editor.o: text_editor.cpp text_editor.h
	$(CC) $(CFLAGS) -c text_editor.cpp

mem_buffer.o: mem_buffer.cpp mem_buffer.h
	$(CC) $(CFLAGS) -c mem_buffer.cpp

clean:
	rm -f *.o text-editor