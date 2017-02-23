SRC_FILES = read_file.c count.c solution.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
HEAD_FILES = $(patsubst %.c, %.h, $(SRC_FILES))
CC = gcc
CCFLAGS = -ansi -pedantic -Wall

all: $(OBJ_FILES)

%.o: %.c $(HEAD_FILES)
	$(CC) $(CCFLAGS) -c $*.c


clean:
	rm $(OBJ_FILES)
