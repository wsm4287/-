/*
 * main.cpp
 *
 * Serial version
 *
 * Compile with -O2
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "skiplist.h"

using namespace std;

// aggregate variables
long sum = 0;
long odd = 0;
long min = INT_MAX;
long max = INT_MIN;
bool done = false;

// function prototypes

int main(int argc, char* argv[])
{
    struct timespec start, stop;

    skiplist<int, int> list(0,1000000);

    // check and parse command line options
    if (argc != 2) {
        printf("Usage: %s <infile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *fn = argv[1];

    clock_gettime( CLOCK_REALTIME, &start);

    // load input file
    FILE* fin = fopen(fn, "r");
    char action;
    long num;
    while (fscanf(fin, "%c %ld\n", &action, &num) > 0) {
        if (action == 'i') {            // insert
            list.insert(num,num);
            // update aggregate variables
            sum += num;
            if (num % 2 == 1) {
                odd++;
            }
        }else if (action == 'q') {      // qeury
            if(list.find(num)!=num)
		cout << "ERROR: Not Found: " << num << endl;
        } else if (action == 'w') {     // wait
            usleep(num);
        } else if (action == 'p') {     // wait
	    cout << list.printList() << endl;
        } else {
            printf("ERROR: Unrecognized action: '%c'\n", action);
            exit(EXIT_FAILURE);
        }
    }
    fclose(fin);
    clock_gettime( CLOCK_REALTIME, &stop);

    // print results
    cout << "Elapsed time: " << (stop.tv_sec - start.tv_sec) + ((double) (stop.tv_nsec - start.tv_nsec))/BILLION << " sec" << endl;

    // clean up and return
    return (EXIT_SUCCESS);

}

