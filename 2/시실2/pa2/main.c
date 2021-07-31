#include "db.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_KEYLEN 1024

int main(int argc, char *argv[])
{
	db_t *DB;
	char key[MAX_KEYLEN];
	char *val;
	int size;
	int ret, cnt, key_len, val_len;

	if (argc != 2) {
		printf("Usage: %s size\n", argv[0]);
		return -1;
	}

	size = atoi(argv[1]);
	DB = db_open(size);
	if (DB == NULL) {
		printf("DB not opened\n");
		return -1;
	}
	printf("DB opened\n");
	
	while ((ret = scanf("%s", key)) != -1) {
		key_len = strlen(key);
		val = db_get(DB, key, key_len, &val_len);
		if (val == NULL) {
			printf("GET [%s]\n", key);
			cnt = 1;
		} else {
			printf("GET [%s]\n", key);
			cnt = *((int*)val) + 1;
			free(val);
		}

		db_put(DB, key, key_len, (char *)&cnt, sizeof(int));
		printf("PUT [%s] [%d]\n", key, cnt);

	}

	db_close(DB);
	printf("DB closed\n");
	return 0;
}
