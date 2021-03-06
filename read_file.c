#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "solution.h"
#include "read_file.h"

void database_free(Pizza* pizza){
    int i;
    for (i = 0; i < pizza->R; i++) {
        free(pizza->cells[i]);
    }
    free(pizza->cells);
    free(pizza);
    pizza = NULL;
}

Database* read_file(char* path){
    FILE *f;
    Database* db;
    int i, j;

    f = fopen(path, "r");
    if(!f) {
        printf("Error opening the file %s.\n", path);
        return NULL;
    }
    db = (Database*)malloc(sizeof(Database));
    if(!pizza) {
        printf("Error allocating memory for the database.\n");
        return NULL;
    }

    fscanf(f, "%d %d %d %d %d\n", &db->V, &db->E, &db->R, &db->C, &db->X);
    for(i = 0; i < db->V-1; i++) {
        fscanf("%d ", &db->videos->size);
        db->videos[i].id = i;
    }
    fscanf("%d\n", &db->videos->size);
    db->videos[i].id = i;

    for (i = 0; i < db->E; i++) {
        db->endpoints[i].id = i;
        fscanf("%d %d\n", &db->endpoints[i].lat_base, &db->endpoints[i].num_cache);
        for(j = 0; j < db->endpoints[i].num_cache; j++) {
            fscanf("%d %d\n", &db->endpoints[i].cache[j].id, &db->endpoints[i].cache[j].latency);
        }
    }


    for (i = 0; i < db->R; i++) {
        fscanf("%d %d %d\n", &db->requests[i].video_id, &db->requests[i].endpoint_id, &db->requests[i].number);
    }

    for (i = 0; i < db->C; i++) {
        db->caches[i].id = i;
    }

    return db;


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
