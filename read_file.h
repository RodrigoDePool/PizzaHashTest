#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int R;
    int C;
    int L;
    int H;
    char** cells;
} Pizza;

Pizza* read_file(char* path);

int cuthalf(Slice sl, int c);
// Devuelve la fila o columna sobre la que se debe cortar. Si c=0, entonces es row. Si c=1, es col.
