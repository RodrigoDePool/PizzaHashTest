#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "library.h"
#include "read_file.h"

int main(int argc, char const *argv[]) {
    Database* db;
    db = read_file((char*)argv[1]);
    printf("%d\n", db->V);
    free(db);

    return 0;
}
