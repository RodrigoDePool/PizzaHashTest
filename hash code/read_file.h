#include <stdio.h>
#include <stdlib.h>



typedef struct {
    int V;
    int E;
    int R;
    int C;
    int X;
    Endpoint[1000] endpoints;
    Request[1000000] requests;
    Video[10000] videos;
} Database;

Database* read_file(char* path);

int cutHalf(Slice sl, int* c);
