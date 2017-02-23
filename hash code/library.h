#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIDS 10000
#define MAX_REQUESTS 1000000

typedef struct {
    int V;
    int E;
    int R;
    int C;
    int X;
    Endpoint[1000] endpoints;
    Request[1000000] requests;
    Video[10000] videos;
} Database;

typedef struct {
    int size;
    int id;
    /*servers where it is put?*/
}Video;

typedef struct {
    int id;
    int lat_base;
    int lat[MAX_VIDS];
    Server cache[1000];
    int num_cache;
}Endpoint;

typedef struct {
    int id;
    int num_videos;
    Video videos[MAX_VIDS];
}Server;

typedef struct {
    int server_id;
    int endpoint_id;
    int number;
}Request;

typedef struct {
    Request request[MAX_REQUEST];
}Reqs;
