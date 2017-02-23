#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "library.h"
#include "read_file.h"



void algorithm1(Database* db){
    int i;
    for (i = 0; i < db->R; i++) {

    }
}




int main(int argc, char const *argv[]) {
    Database* db;
    db = read_file((char*)argv[1]);
    printf("%d\n", db->V);

    printf("%d\n", db->requests[db->R-1].number);
    free(db);
    return 0;
}
