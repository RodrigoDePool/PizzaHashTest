#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIDS 10000
#define MAX_CACHE 1000
#define MAX_REQUESTS 1000000

typedef struct{
	int size;
	int id;
	/*servers where it is put?*/
}Video;

typedef struct{
	int id;
	int lat_base;
	int lat[MAX_VIDS];
	int cache_id[MAX_CACHE];
	int num_cache;
}Endpoint;

typedef struct{
	int id;
	int num_videos;
	Video videos[MAX_VIDS];
}Server;

typedef struct{
	int server_id;
	int endpoint_id;
	int number;
}Request;


Video* new_video(int id, int size);

Endpoint* new_endopint(int id, int lat_base, int* lat, int* cache);

Server* new_server(int id);

Request* new_request(int server_id, int endpoint_id, int number);

int server_add_video(int server_id, Video* video);

