#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "library.h"
#include "read_file.h"


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
    if(!db) {
        printf("Error allocating memory for the database.\n");
        return NULL;
    }

    fscanf(f, "%d %d %d %d %d\n", &db->V, &db->E, &db->R, &db->C, &db->X);
    for(i = 0; i < db->V-1; i++) {
        fscanf(f, "%d ", &db->videos->size);
        db->videos[i].id = i;
    }
    fscanf(f, "%d\n", &db->videos->size);
    db->videos[i].id = i;

    for (i = 0; i < db->E; i++) {
        db->endpoints[i].id = i;
        fscanf(f, "%d %d\n", &db->endpoints[i].lat_base, &db->endpoints[i].num_cache);
        for(j = 0; j < db->endpoints[i].num_cache; j++) {
            fscanf(f, "%d %d\n", &db->endpoints[i].cache[j].id, &db->endpoints[i].cache[j].latency);
        }
    }


    for (i = 0; i < db->R; i++) {
        fscanf(f, "%d %d %d\n", &db->requests[i].video_id, &db->requests[i].endpoint_id, &db->requests[i].number);
    }

    for (i = 0; i < db->C; i++) {
        db->caches[i].id = i;
    }
    fclose(f);
    return db;


}


void write_file(Database* db){
    int i, j;

    fopen("me_at_the_zoo.out", "w");

    fprintf("%d\n", db->num_cache);

    for (i = 0; i < db->num_cache; i++) {
        fprintf("%d ", db->caches[i].id);
        for(j = 0; j < db->caches[i].num_videos-1; j++) {
            fprintf("%d ", db->caches[i].videos[j].id);
        }
        fprintf("%d\n", db->caches[i].videos[j].id);
    }


    fclose(f);
}
