#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIDS 10000
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
    int lat[MAX_VIDS];
    Conexion cache[1000];
    int num_cache;
}Endpoint;



typedef struct {
    int id;
    int num_videos;
    Video videos[10000];
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
    Video videos[10000];
} Database;


#endif
