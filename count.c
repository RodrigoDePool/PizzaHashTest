#include <stdio.h>
#include <stdlib.h>
#include <readfile.h>

int contar(Pizza pizza){
    int i=0, j=0;
    int count;
    char c;

    count=0;

    for (i=0; i<pizza.R; i++){
        for(j=0; j<pizza.C; j++){
            c = pizza.cells[i][j];
            if(c == 'T')
              count++;
            }
        }
    }

    return count;
}
