/*
 * SWE3005-43 Introduction to Computer Architectures (Fall 2019)
 *
 * Instructor: Prof. Jinkyu Jeong (jinkyu@skku.edu)
 *
 * TA: Minwoo Ahn (minwoo.ahn@csi.skku.edu), Sunghwan Kim (sunghwan.kim@csi.skku.edu)
 * Office: Semiconductor Buildnig #400509
 *
 * Author: Minwoo Ahn
 * Description: CPU Cache Simulator
 *
 * Copyright (c) 2019 Sungkyunkwan Univ. CSI (Computer Systems and Intelligence Lab)
 */

#include "mem.h"

/* Global Variables */
int cycle = 0;
int hit_count[2] = {0};
int miss_count[2] = {0};

/* Variables for pa3_check */
int cache_level;
int memory_access;

int main() {
	char config_file[15];
	char input_file[20];
	char output_file[50];
	char policy[4];
	FILE *fd_config;
	FILE *fd_input;
	FILE *fd_output;
	char op;		//Read or Write of request
	unsigned int phy_addr;

	/* Get Input */
	strcpy(config_file, "cache.config");
	strcpy(input_file, "cache.input");
	strcpy(output_file, "cache.output");

	fd_config = fopen(config_file, "r");
	if(fd_config == NULL) {
		printf("There is no file such %s\n", config_file);
		exit(1);
	}

	fscanf(fd_config, "%d", &cache_level);
	fscanf(fd_config, "%d", &memory_access);

	fscanf(fd_config, "%d", &cache[0].size);
	fscanf(fd_config, "%d", &cache[0].num_entry);
	fscanf(fd_config, "%d", &cache[0].num_ways);

	fscanf(fd_config, "%s", policy);
	if (!strcmp(policy, "LRU"))
		cache[0].replace = LRU;
	else
		cache[0].replace = FIFO;

	fscanf(fd_config, "%s", policy);
	if (!strcmp(policy, "WB"))
		cache[0].write = WB;
	else
		cache[0].write = WT;

	fscanf(fd_config, "%d", &cache[0].access_cycle);

	cache[0].bytes_per_block = 4;
	cache[0].block_per_entry = cache[0].size / cache[0].num_ways / cache[0].num_entry / cache[0].bytes_per_block;

	if(cache_level == 2) {
		fscanf(fd_config, "%d", &cache[1].size);
		fscanf(fd_config, "%d", &cache[1].num_entry);
		fscanf(fd_config, "%d", &cache[1].num_ways);

		fscanf(fd_config, "%s", policy);
		if (!strcmp(policy, "LRU"))
			cache[1].replace = LRU;
		else
			cache[1].replace = FIFO;

		fscanf(fd_config, "%s", policy);
		if (!strcmp(policy, "WB"))
			cache[1].write = WB;
		else
			cache[1].write = WT;

		fscanf(fd_config, "%d", &cache[1].access_cycle);

		cache[1].bytes_per_block = 4;
		cache[1].block_per_entry = cache[1].size / cache[1].num_ways / cache[1].num_entry / cache[1].bytes_per_block;
	}

	initialize();

	/* Open Input & Output Files */
	fd_input = fopen(input_file, "r");
	if (fd_input == NULL) {
		printf("There is no file such %s\n", input_file);
		exit(1);
	}

	fd_output = fopen(output_file, "w+");
	/* Start Simulation */
	while(1) {
		fscanf(fd_input, "%c ", &op);
		
		switch(op) {
			case 'R':	//Read Operation
				fscanf(fd_input, "%x ", &phy_addr);
				read_op(phy_addr);
				break;
			case 'W':	//Write Operation
				fscanf(fd_input, "%x ", &phy_addr);
				write_op(phy_addr);
				break;
			default:	//HALT
				goto end;
		};
	}

end:
	fclose(fd_config);
	fclose(fd_input);
	/*	Print Results	  */
	print_result(fd_output);
	fclose(fd_output);

	destroy();

	return 0;
}

void initialize() {
	int n, i, j;
	
	printf("Initialize Your Cache...\n");

	/* cache.way_cache[way #][entry #]*/
	for(n = 0; n < cache_level; n++) {
		cache[n].way_cache = (struct cache_entry **)malloc(sizeof(struct cache_entry *) * cache[n].num_ways);
		
		for (i = 0; i < cache[n].num_ways; i++)
			cache[n].way_cache[i] = (struct cache_entry *)malloc(sizeof(struct cache_entry) * cache[n].num_entry);
		
		for (i = 0; i < cache[n].num_ways; i++) {
			for (j = 0; j < cache[n].num_entry; j++) {				
				/* Initialize other variables in your cache_entry structure! */
				/* e.g. valid, dirty, tag, etc.                              */
				cache[n].way_cache[i][j].valid = 0;
				cache[n].way_cache[i][j].tag = 0;
				cache[n].way_cache[i][j].dirty = 0;
				///////////////////////////////////////////////////////////////
			}
		}
	}

	printf("Finished to Initialize Your Cache!\n\n");
}

void destroy() {
	int n, i;

	printf("Destroy Your Cache...\n");
	for (n = 0; n < cache_level; n++) {
		for (i = 0; i < cache[n].num_ways; i++) {
			free(cache[n].way_cache[i]);
		}
		free(cache[n].way_cache);
	}
	printf("Finished to Destroy Your Cache!\n");
}


void read_op(unsigned int addr) {
	/* You have to implement your own read_op function here! */
	cycle += cache[0].access_cycle;

	int id = 1;
	int i=0;
	int t=0;
	for(i =0; id!= cache[0].num_entry; i++)
		id= id *2;
	id =1;
	for(t=0; id!= cache[0].block_per_entry; t++)
		id = id*2;
	int bi = 2 + i + t;
	int x=1;

	for(int k=0; k<bi-1; k++)
		x = x*2+1;
	x = x & addr;
	
	int y = addr >> bi;
	int a = x >> (bi-i);
	int b = x >> (bi-i-t);

	int hit =-1;
	int k;
	for(k=0; k<cache[0].num_ways; k++){
		if(cache[0].way_cache[k][a].valid){
			if(cache[0].way_cache[k][a].tag== y){
				hit =k;
				break;
				}
			}
	}
	k=0;
	while(k<cache[0].num_ways){
		if(cache[0].way_cache[k][a].valid==0)
			break;
		k++;
		}
	if(cache[0].replace == LRU){
		if(k==cache[0].num_ways&&hit==-1){
			if(cache[0].write == WB&&cache[0].way_cache[0][a].dirty==1){
				if(cache_level == 2)
					cycle += cache[1].access_cycle;
				else
					cycle += memory_access;
			}
			for(int p=0; p<k-1; p++){
				cache[0].way_cache[p][a].valid = cache[0].way_cache[p+1][a].valid;
				cache[0].way_cache[p][a].tag = cache[0].way_cache[p+1][a].tag;
				cache[0].way_cache[p][a].dirty = cache[0].way_cache[p+1][a].dirty;
			}
			cache[0].way_cache[k-1][a].valid = 1;
			cache[0].way_cache[k-1][a].tag = y;
			cache[0].way_cache[k-1][a].dirty = 0;
		}
		else if(k!=cache[0].num_ways&&hit==-1){
			cache[0].way_cache[k][a].valid = 1;
			cache[0].way_cache[k][a].tag = y;
			cache[0].way_cache[k][a].dirty = 0;
		}
	}
	else{
		if(k==cache[0].num_ways&&hit==-1){
			if(cache[0].write == WB&&cache[0].way_cache[0][a].dirty==1){
				if(cache_level == 2)
					cycle += cache[1].access_cycle;
				else
					cycle += memory_access;
			}
			cache[0].way_cache[0][a].valid = 1;
			cache[0].way_cache[0][a].tag = y;
			cache[0].way_cache[0][a].dirty = 0;
		}
		else if(k!=cache[0].num_ways&&hit==-1){
			cache[0].way_cache[k][a].valid = 1;
			cache[0].way_cache[k][a].tag = y;
			cache[0].way_cache[k][a].dirty = 0;
		}
			

	}
	if(hit!=-1){
		hit_count[0]++;
		}
	else{
		miss_count[0]++;
		if(cache_level!=1){
			cycle += cache[1].access_cycle;
			for(k=0; k<cache[1].num_ways; k++){
				if(cache[1].way_cache[k][a].valid){
					if(cache[1].way_cache[k][a].tag== y){
						hit =k;
						break;
						}
					}
			}
			k=0;
			while(k<cache[1].num_ways){
				if(cache[1].way_cache[k][a].valid==0)
					break;
				k++;
				}
			if(cache[1].replace == LRU){
				if(k==cache[1].num_ways&&hit==-1){
					if(cache[1].write == WB&&cache[1].way_cache[0][a].dirty==1){
						cycle += memory_access;
						}
					for(int p=0; p<k-1; p++){
						cache[1].way_cache[p][a].valid = cache[1].way_cache[p+1][a].valid;
						cache[1].way_cache[p][a].tag = cache[1].way_cache[p+1][a].tag;
						cache[1].way_cache[p][a].dirty = cache[1].way_cache[p+1][a].dirty;
					}
					cache[1].way_cache[k-1][a].valid = 1;
					cache[1].way_cache[k-1][a].tag = y;
					cache[1].way_cache[k-1][a].dirty = 0;
				}
				else if(k!=cache[1].num_ways&&hit==-1){
					cache[1].way_cache[k][a].valid = 1;
					cache[1].way_cache[k][a].tag = y;
					cache[1].way_cache[k][a].dirty = 0;
				}
			}
			else{
				if(k==cache[1].num_ways&&hit==-1){
					if(cache[1].write == WB&&cache[1].way_cache[0][a].dirty==1){
						cycle += memory_access;
						}
					cache[1].way_cache[0][a].valid = 1;
					cache[1].way_cache[0][a].tag = y;
					cache[1].way_cache[0][a].dirty = 0;
				}
				else if(k!=cache[1].num_ways&&hit==-1){
					cache[1].way_cache[k][a].valid = 1;
					cache[1].way_cache[k][a].tag = y;
					cache[1].way_cache[k][a].dirty = 0;
				}
			}

		}
		if(hit!=-1)
			hit_count[1]++;
		else{
			miss_count[1]++;
			cycle += memory_access;
			}
	
	}

	///////////////////////////////////////////////////////////
}

void write_op(unsigned int addr) {
	/* You have to implement your own read_op function here! */
	cycle += cache[0].access_cycle;

	int id = 1;
	int i=0;
	int t=0;
	for(i =0; id!= cache[0].num_entry; i++)
		id= id *2;
	id =1;
	for(t=0; id!= cache[0].block_per_entry; t++)
		id = id*2;
	int bi = 2 + i + t;
	int x=1;

	for(int k=0; k<bi-1; k++)
		x = x*2+1;
	x = x & addr;
	
	int y = addr >> bi;
	int a = x >> (bi-i);
	int b = x >> (bi-i-t);

	int hit =-1;
	int k;
	for(k=0; k<cache[0].num_ways; k++){
		if(cache[0].way_cache[k][a].valid){
			if(cache[0].way_cache[k][a].tag== y){
				hit =k;
				break;
				}
			}
	}

	if(cache[0].write == WT){
		if(cache_level==2)
			cycle += cache[1].access_cycle;
		else
			cycle += memory_access;
	}
	k=0;
	while(k<cache[0].num_ways){
		if(cache[0].way_cache[k][a].valid==0)
			break;
		k++;
		}
	if(cache[0].replace == LRU){
		if(k==cache[0].num_ways&&hit==-1){
			if(cache[0].write == WB&&cache[0].way_cache[0][a].dirty==1){
				if(cache_level ==2)
					cycle += cache[1].access_cycle;
				else
					cycle += memory_access;
			}
			for(int p=0; p<k-1; p++){
				cache[0].way_cache[p][a].valid = cache[0].way_cache[p+1][a].valid;
				cache[0].way_cache[p][a].tag = cache[0].way_cache[p+1][a].tag;
				cache[0].way_cache[p][a].dirty = cache[0].way_cache[p+1][a].dirty;
			}
			cache[0].way_cache[k-1][a].valid = 1;
			cache[0].way_cache[k-1][a].tag = y;
			if(cache[0].write == WB)
				cache[0].way_cache[k-1][a].dirty = 1;
		}
		else if(k!=cache[0].num_ways&&hit==-1){
			cache[0].way_cache[k][a].valid = 1;
			cache[0].way_cache[k][a].tag = y;
			if(cache[0].write == WB)
				cache[0].way_cache[k][a].dirty = 1;
		}
	}
	else{
		if(k==cache[0].num_ways&&hit==-1){
			if(cache[0].write == WB&&cache[0].way_cache[0][a].dirty==1){
				if(cache_level ==2)
					cycle += cache[1].access_cycle;
				else
					cycle += memory_access;
			}
			cache[0].way_cache[0][a].valid = 1;
			cache[0].way_cache[0][a].tag = y;
			if(cache[0].write == WB)
				cache[0].way_cache[0][a].dirty = 1;
		}
		else if(k!=cache[0].num_ways&&hit==-1){
			cache[0].way_cache[k][a].valid = 1;
			cache[0].way_cache[k][a].tag = y;
			if(cache[0].write == WB)
				cache[0].way_cache[k][a].dirty = 1;
		}
			

	}
	if(hit!=-1){
		hit_count[0]++;
		}
	else{
		miss_count[0]++;
		if(cache_level!=1){
			if(cache[1].write == WT)
				cycle += memory_access;
			cycle += cache[1].access_cycle;
			for(k=0; k<cache[1].num_ways; k++){
				if(cache[1].way_cache[k][a].valid){
					if(cache[1].way_cache[k][a].tag== y){
						hit =k;
						break;
						}
					}
			}
			k=0;
			while(k<cache[1].num_ways){
				if(cache[1].way_cache[k][a].valid==0)
					break;
				k++;
				}
			if(cache[1].replace == LRU){
				if(k==cache[1].num_ways&&hit==-1){
					if(cache[1].write == WB&&cache[1].way_cache[0][a].dirty==1){
							cycle += memory_access;
					}	
					for(int p=0; p<k-1; p++){
						cache[1].way_cache[p][a].valid = cache[1].way_cache[p+1][a].valid;
						cache[1].way_cache[p][a].tag = cache[1].way_cache[p+1][a].tag;
						cache[1].way_cache[p][a].dirty = cache[1].way_cache[p+1][a].dirty;
					}
					cache[1].way_cache[k-1][a].valid = 1;
					cache[1].way_cache[k-1][a].tag = y;
					if(cache[1].write == WB){
						cache[1].way_cache[k-1][a].dirty = 1;
						}
				}
				else if(k!=cache[1].num_ways&&hit==-1){
					cache[1].way_cache[k][a].valid = 1;
					cache[1].way_cache[k][a].tag = y;
					if(cache[1].write == WB)
						cache[1].way_cache[k][a].dirty = 1;
				}
			}
			else{
				if(k==cache[1].num_ways&&hit==-1){
					if(cache[1].write == WB&&cache[1].way_cache[0][a].dirty==1){
							cycle += memory_access;
					}	
					cache[1].way_cache[0][a].valid = 1;
					cache[1].way_cache[0][a].tag = y;
					if(cache[1].write == WB){
						cache[1].way_cache[0][a].dirty = 1;
						}
				}
				else if(k!=cache[1].num_ways&&hit==-1){
					cache[1].way_cache[k][a].valid = 1;
					cache[1].way_cache[k][a].tag = y;
					if(cache[1].write == WB)
						cache[1].way_cache[k][a].dirty = 1;
				}
			

			}
		}
		if(hit!=-1)
			hit_count[1]++;
		else{
			miss_count[1]++;
			cycle += memory_access;
			}
	}

	///////////////////////////////////////////////////////////
}

void print_result(FILE *in) {
	fprintf(in, "Level 1 Cache\n");
	fprintf(in, "Hit Count : %d\n", hit_count[0]);
	fprintf(in, "Miss Count : %d\n", miss_count[0]);
	fprintf(in, "Hit Ratio : %.3f\n", (double)hit_count[0] / (double)(hit_count[0] + miss_count[0]));
	if(cache_level == 2) {
		fprintf(in, "\nLevel 2 Cache\n");
		fprintf(in, "Hit Count : %d\n", hit_count[1]);
		fprintf(in, "Miss Count : %d\n", miss_count[1]);
		fprintf(in, "Hit Ratio : %.3f\n", (double)hit_count[1] / (double)(hit_count[1] + miss_count[1]));
	} else {
		hit_count[1] = 0;
		miss_count[1] = 0;
	}
	fprintf(in, "\nTotal Hit Ratio : %.3f\n", (double)(hit_count[0] + hit_count[1]) / (double)(hit_count[0] + miss_count[0]));
	fprintf(in, "Total cycle: %d\n", cycle);
}
