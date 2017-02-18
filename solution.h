#ifndef SOLUTION_H
#include <stdio.h>
#include <stdlib.h>

#define MAX_SLICES 3000

typedef struct _Solution Solution;
typedef struct _Slice Slice;

typedef struct{
    int nslices;
    Slice slices[MAX_SLICES];  
} Solution;


struct{
    int sol[4];
} Slice;



int addSlice(Solution *s,Slice *sl);
int printSolution(Solution *s, char *path);




/*
    Copies 1 slice to another slice
*/
int copySlice(Slice *sl1, Slice *sl2);


void freeSlice(Slice *sl);
void freeSolution(Solution *s);


#endif
