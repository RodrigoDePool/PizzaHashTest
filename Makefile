SRC_FILES = read_file.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
HEAD_FILES = $(patsubst %.c, %.h, $(SRC_FILES))
CC = gcc
CCFLAGS = -ansi -pedantic -Wall

all: read_file.o

read_file.o: read_file.c read_file.h
	$(CC) $(CCFLAGS) -c read_file.c


clean:
	rm $(OBJ_FILES)
