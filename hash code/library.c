#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

/* Privadas */
Cache* seek_cache(Database *db, int id){
	
	if(id<0)
		return NULL;

	int i;

	for(i=0; i<MAX_CACHE; i++){
		if(db->caches[i].id == id)
			return &db->caches[i];
	}

	return NULL;
}

Endpoint* seek_endpoint(Database *db, int id){
	
	if(id<0)
		return NULL;

	int i;

	for(i=0; i<MAX_CACHE; i++){
		if(db->endpoints[i].id == id)
			return &db->endpoints[i];
	}

	return NULL;
}




Video* seek_video(Database *db, int id){
	
	if(id<0)
		return NULL;

	int i;

	for(i=0; i<MAX_CACHE; i++){
		if(db->videos[i].id == id)
			return &db->videos[i];
	}

	return NULL;
}

int seek_video_cache(Cache *cache, int id){
	
	if(id<0)
		return 0;

	int i;

	for(i=0; i<cache->num_videos; i++){
		if(cache->videos[i] == id)
			return 1;
	}

	return 0;
}


/*Video* new_video(int id, int size){
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

Request* new_request(int server_id, int endpoint_id, int number); */

Cache* cache_add_video(Database* db, int server_id, int id_video){
    Video *video;
	if(!db || server_id < 0 || id_video<0)
		return NULL;

	Cache* cache = NULL;

    video=seek_video(db,id_video);

	cache = seek_cache(db, server_id);
	
	cache->videos[cache->num_videos] = id_video;

    if(cache->num_videos==0)
        db->num_cache++;

	cache->num_videos++;

	cache->free_mem -= video->size;

	return cache;
}

void solve(Database* db){
	if(!db)
		return;

	int i = 0;

	for(i=db->R-1; i>=0; --i){
		answer_request(db, &db->requests[i]);
	}

}

void answer_request(Database* db, Request* request){
	
	Endpoint* endpoint;
	Video* video;
	Cache** cache;
	Cache* temp;
	int size, j, i;

	endpoint = &db->endpoints[request->endpoint_id];
	video = &db->videos[request->video_id];
	size = video->size;

	cache = (Cache **) malloc(db->C*sizeof(Cache *));

	for(j=0; j<endpoint->num_cache; j++){
		cache[j] = seek_cache(db, endpoint->cache[j].id);
		i=j;
		while(endpoint->cache[i].latency < endpoint->cache[i].latency && i > 0){
		temp = cache[i-1];
		cache[i-1]=cache[i];
		cache[i]=temp;
		i--;
		}
	}
	for(j=0; j<endpoint->num_cache; j++){
		if(seek_video_cache(cache[j], video->id)==1){
			free(cache);
			return;
		}
	
		if(size<=(cache[j]->free_mem)){
			cache_add_video(db, endpoint->cache[j].id, video->id);
			break;
		}
	}
	free(cache);
}


