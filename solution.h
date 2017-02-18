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


/*
    0 if error 
    1 if added
*/
int addSlice(Solution *s,Slice *sl);
int printSolution(Solution s, char *path);




/*
    Copies slice1 to slice2
*/
int copySlice(Slice *sl1, Slice *sl2);


#endif
