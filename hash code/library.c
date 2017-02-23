#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

Video* new_video(int id, int size){
	if(id < 1 || size < 0)
		return NULL;
	Video* video = NULL;

	video = (Video*) malloc(sizeof(Video));
	if(!video)
		return NULL;

	video->id = id;
	video->size = size;

	return video;
}

Endpoint* new_endopint(int id, int lat_base, int* lat, int* cache);

Server* new_server(int id);

Request* new_request(int server_id, int endpoint_id, int number);

int server_add_video(int server_id, Video* video);

