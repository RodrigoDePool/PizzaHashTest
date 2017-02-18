#include <stdio.h>
#include <stdlib.h>
#include <readfile.h>

int* contar(Pizza pizza){
    int i=0, j=0;
    int *count;
    char c;

    count = (int *)malloc(2*sizeof(int));
    if(!count)
      return NULL;
    count[0]=count[1]=0;


    for (i=0; i<pizza.R; i++){
        for(j=0; j<pizza.C; j++){
            c = pizza.cells[i][j];
            if(c == 'T')
              count[0]++;
            if(c == 'M'){
              count[1]++;
            }
        }
    }

    return count;
}
