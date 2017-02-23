#include <stdio.h>
#include <stdlib.h>
#include <readfile.h>

int contar(Pizza pizza, x1, y1, x2, y2){

  if(!pizza)
    return -3;
  if(x1>=x2 || x1>=pizza->R || x2>=pizza->R)
    return -1;
  if(y1>=y2 || y1>=pizza->C || y2>=pizza->C)
    return -2;

    int i, j;
    int count;
    char c;

    count=0;

    for (i=x; i<x2; i++){
        for(j=y; j<y2; j++){
            c = pizza->cells[i][j];
            if(c == 'T')
              count++;
            }
        }
    }

    return count;
}
