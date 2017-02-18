#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int R;
    int C;
    int L;
    int H;
    char** cells;
} Pizza;

int read_file(char* path);
