#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

Video* new_video(int id, int size){
	if(id < 0 || size < 0)
		return NULL;
	Video* video = NULL;

	video = (Video*) malloc(sizeof(Video));
	if(!video)
		return NULL;

	video->id = id;
	video->size = size;

	return video;
}

Endpoint* new_endopint(int id, int lat_base, Conexion* conex){
	if(id < 0 || lat_base < 0 || !conex)
		return NULL;

	int i=0;
	Endpoint* endpoint = NULL;

	endpoint = (Endpoint*) malloc(sizeof(Endpoint));
	if(!endpoint)
		return NULL;

	endpoint->id = id;
	endpoint->lat_base = lat_base;
	
	for(i=0; i<MAX_CACHE; i++){
		if(conex[i]<0)
			break;
		
		endpoint->cache = conex[i]; 
	}

	return endpoint;
}

Request* new_request(int server_id, int endpoint_id, int number);

Cache* cache_add_video(Database* db, int server_id, Video* video){

	if(!db || server_id < 0 || !video)
		return NULL;

	Cache* cache = NULL;

	cache = seek_cache(db, server_id);
	
	cache->videos[cache->num_video] = video;

	cache->num_videos++;

	return cache;
}

Cache* seek_cache(Database db, int id){
	
	if(id<0)
		return NULL;

	int i;

	for(i=0; i<MAX_CACHE; i++){
		if(db->caches[i]->id == id)
			return db->caches[i];
	}

	return NULL;
}

Cache* seek_endpoint(Database db, int id){
	
	if(id<0)
		return NULL;

	int i;

	for(i=0; i<MAX_CACHE; i++){
		if(db->endpoints[i]->id == id)
			return db->caches[i];
	}

	return NULL;
}

Cache* seek_request(Database db, int id){
	
	if(id<0)
		return NULL;

	int i;

	for(i=0; i<MAX_CACHE; i++){
		if(db->requests[i]->id == id)
			return db->caches[i];
	}

	return NULL;
}

Cache* seek_video(Database db, int id){
	
	if(id<0)
		return NULL;

	int i;

	for(i=0; i<MAX_CACHE; i++){
		if(db->videos[i]->id == id)
			return db->caches[i];
	}

	return NULL;
}

