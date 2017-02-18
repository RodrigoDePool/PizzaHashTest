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


Solution *newSolution();

int addSlice(Solution *s,Slice *sl);
int printSolution(Solution *s, char *path);


Slice *newSlice(int ri, int ci, int rf, int cf);
int getIRow(Slice *sl);
int getFRow(Slice *sl);
int getICol(Slice *sl);
int getFCol(Slice *sl);

int newFCol(Slice *sl, int cf);
int newFRow(Slice *sl, int rf);
int newICol(Slice *sl, int ci);
int newIRow(Slice *sl, int ri);

Slice *copySlice(Slice *sl);


void freeSlice(Slice *sl);
void freeSolution(Solution *s);


#endif
