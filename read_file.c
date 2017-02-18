#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "solution.h"
#include "read_file.h"

void pizza_free(Pizza* pizza){
    int i;
    for (i = 0; i < pizza->R; i++) {
        free(pizza->cells[i]);
    }
    free(pizza->cells);
    free(pizza);
    pizza = NULL;
}

Pizza* read_file(char* path){
    FILE *f;
    Pizza* pizza;
    int i, j;

    f = fopen(path, "r");
    if(!f) {
        printf("Error opening the file %s.\n", path);
        return NULL;
    }
    pizza = (Pizza*)malloc(sizeof(Pizza));
    if(!pizza) {
        printf("Error allocating memory for the pizza.\n");
        return NULL;
    }

    fscanf(f, "%d %d %d %d\n", &pizza->R, &pizza->C, &pizza->L, &pizza->H);
    pizza->cells = (char**)malloc(pizza->R*sizeof(char*));
    if(!pizza->cells) {
        printf("Error allocating memory for the array of pizza.\n");
        free(pizza);
        return NULL;
    }
    for(i = 0; i < pizza->R; i++) {
        pizza->cells[i] = (char*)malloc((pizza->C+1)*sizeof(char));
        if(!pizza->cells[i]) {
            printf("Error allocating memory for individual cells.\n");
            for(j = 0; j < i; j++) {
                free(pizza->cells[j]);
            }
            free(pizza->cells);
            free(pizza);
            return NULL;
        }
    }

    for(i = 0; i < pizza->R; i++) {
        fgets(pizza->cells[i], pizza->C + 1, f);
        pizza->cells[i][strlen(pizza->cells[i])-1] = 0;
    }
    return pizza;


}


int cutHalf(Slice sl, int* c){
    int half = -1;

    if((sl.sol[2]-sl.sol[0]) > (sl.sol[3]-sl.sol[1])) { /*horizontal (return row)*/
        half = (sl.sol[2]+sl.sol[0])/2;
        *c = 0;
        return half;
    } else { /*vertical (return col)*/
        half = (sl.sol[3]+sl.sol[1])/2;
        *c = 1;
        return half;
    }
    return half;
}
