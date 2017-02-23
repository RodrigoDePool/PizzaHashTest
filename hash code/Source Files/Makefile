SRC_FILES = read_file.c library.c 
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES)) main.o
HEAD_FILES = read_file.h library.h
CC = gcc
CCFLAGS = -ansi -pedantic -Wall

all: main

%.o: %.c $(HEAD_FILES)
	$(CC) $(CCFLAGS) -c $*.c

main.o: $(HEAD_FILES) main.c
	$(CC) $(CCFLAGS) -c main.c

main: $(OBJ_FILES) $(HEAD_FILES) main.o
	$(CC) $(CCFLAGS) -o main read_file.o main.o library.o

clean:
	rm $(OBJ_FILES)
