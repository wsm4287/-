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

#ifndef __mem__
#define __mem__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum replace_policy {
	LRU,	//Least recently used
	FIFO		//First-in-First-out
};

enum write_policy {
	WB,		//Write-back
	WT		//Write-through
};

struct cache_entry {
	char valid;
	char dirty;
	unsigned int tag;
	/* You can add variables for your purpose  */
};

struct cache {
	struct cache_entry **way_cache;
	int size;
	int num_entry;
	int num_ways;
	int block_per_entry;		// # of blocks / entry
	int bytes_per_block;		// # of bytes / block
	enum replace_policy replace;		// LRU or FIFO
	enum write_policy write;		// WB or WT
	int access_cycle;
};

struct cache cache[2];

void read_op(unsigned int);
void write_op(unsigned int);

/* Flush data in cache to disk*/
void print_result(FILE *);

/* Initialization before start simulation. */
void initialize(void);
/* Destroy after simulation */
void destroy(void);
#endif
