#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIDS 10000
#define MAX_CACHE 1000
#define MAX_REQUESTS 1000000

typedef struct {
    int V;
    int E;
    int R;
    int C;
    int X;
    Endpoint[1000] endpoints;
    Request[1000000] requests;
    Cache[1000] caches;
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
    Conexion cache[1000];
    int num_cache;
}Endpoint;

typedef struct {
    int id;
    int latency;
}Conexion;

typedef struct {
    int id;
    int num_videos;
    Video[10000] videos;
}Cache;

typedef struct {
    int video_id;
    int endpoint_id;
    int number;
}Request;

Video* new_video(int id, int size);

Endpoint* new_endopint(int id, int lat_base, int* lat, int* cache);

Request* new_request(int server_id, int endpoint_id, int number);

int server_add_video(Database db, int server_id, Video* video);


