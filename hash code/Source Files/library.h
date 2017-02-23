#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIDS 10000
#define MAX_CACHE 1000
#define MAX_REQUESTS 1000000

typedef struct {
    int id;
    int latency;
}Conexion;

typedef struct {
    int size;
    int id;
    /*servers where it is put?*/
}Video;


typedef struct {
    int id;
    int lat_base;
    Conexion cache[1000];
    int num_cache;
}Endpoint;



typedef struct {
    int id;
    int num_videos;
    int free_mem;
    int videos[10000];
}Cache;

typedef struct {
    int video_id;
    int endpoint_id;
    int number;
}Request;


typedef struct {
    int V;
    int E;
    int R;
    int C;
    int X;
    Endpoint endpoints[1000];
    Request requests[1000000];
    Cache caches[1000];
    int num_cache;
    Video videos[10000];
} Database;

Video* new_video(int id, int size);

Endpoint* new_endopint(int id, int lat_base, int* lat, int* cache);

Request* new_request(int server_id, int endpoint_id, int number);

int server_add_video(Database* db, int server_id, int id_video);

void solve(Database* db);

void answer_request(Database* db, Request* request);

#endif
