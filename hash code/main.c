#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "library.h"
#include "read_file.h"



void algorithm1(Database* db){
    int i, j, k, flag;
    int eid;
    int cid;
    int vid;
    int number;
    int size;
    for (i = 0; i < db->R; i++) {
        eid = db->requests[i].endpoint_id;
        vid = db->requests[i].video_id;
        number = db->requests[i].number;
        size = db->videos[vid].size;
        for(j = 0; j < db->endpoints[eid].num_cache; j++) {
            cid = db->endpoints[eid].cache[j].id;
            if(db->caches[cid].free_mem > size) {
                flag = 0;
                for(k = 0; k < db->caches[cid].num_videos; k++) {
                    if(db->caches[cid].videos[k] == vid) {
                        flag = 1;
                    }
                }
                if(flag == 0) {
                    db->caches[cid].videos[db->caches[cid].num_videos] = vid;
                    if(db->caches[cid].num_videos == 0) {
                        db->num_cache++;
                    }
                    db->caches[cid].free_mem = db->caches[cid].free_mem - size;
                    db->caches[cid].num_videos++;
                    break;
                }
            }
        }
    }
    write_file(db);
}




int main(int argc, char const *argv[]) {
    Database* db;
    db = read_file((char*)argv[1]);
    printf("%d\n", db->V);
    algorithm1(db);
    printf("%d\n", db->requests[db->R-1].number);
    free(db);
    return 0;
}
