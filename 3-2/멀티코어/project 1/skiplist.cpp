/*
 *main.cpp
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
#include <pthread.h>

using namespace std;

// aggregate variables
long sum = 0;
long odd = 0;
long min = INT_MAX;
long max = INT_MIN;
bool done = false;
int N;
char action;
long num;
skiplist<int, int> list(0,1000000);
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cn = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t pn = PTHREAD_MUTEX_INITIALIZER;
//pthread_t id;
int kk=0;
int ss=0;
int ready;
int endi;
// function prototypes

void *create(void *){
    pthread_mutex_lock(&lock);
    int i=0;
//    pthread_cond_wait(&cond, &lock);
//    pthread_mutex_unlock(&lock);
    char act;
    long n;
    ready--;
    pthread_cond_wait(&cond, &lock);
    while(1){  
        act = action;
        n = num;
        kk=1;
        //cout << act << " " << num << endl;
        if (act == 'i') {            // insert
            list.insert(n,n);
            // update aggregate variables
            sum += n;
            if (n % 2 == 1) {
                odd++;
            }
        }else if (act == 'q') {      // qeury
            if(list.find(n)!=n)
	        cout << "ERROR: Not Found: " << n << endl;
        }else if (act == 'w') {     // wait
            usleep(n);
        }
				endi = 1;
        pthread_cond_wait(&cond, &lock);
    }
    pthread_mutex_unlock(&lock);
}


int main(int argc, char* argv[])
{
    struct timespec start, stop;


    // check and parse command line options
    if (argc != 3) {
        printf("Usage: sum <infile> <num>\n");
        exit(EXIT_FAILURE);
    }
    char *fn = argv[1];
    N = atoi(argv[2]);
    pthread_t threads[N];
    clock_gettime( CLOCK_REALTIME, &start);
    // load numbers and add them to the queue
    FILE* fin = fopen(fn, "r");
//    char action;
//    long num;
    int i;
    ready = N;
    for(i=0; i<N; i++){
       pthread_create(&threads[i], NULL, create, NULL);
    }
    while(ready);
	  if(N>1){
    while (1) { 
       if(fscanf(fin, "%c %ld\n", &action, &num) >=1){
           if (action == 'i' || action == 'q' || action == 'w' ) {            // insert
                pthread_cond_signal(&cond);
                while(kk == 0);
                if(kk == 1){
                   kk = 0;
                }
            }
            else if (action == 'p') {     // wait 
		
	        cout << "fdf"<< list.printList() << endl;
            }
            else {
                printf("ERROR: Unrecognized action: '%c'\n", action);
                exit(EXIT_FAILURE);
            }
        }
        else break;
    }
	  }
	  else{       
		  while (1){
		    if(fscanf(fin, "%c %ld\n", &action, &num) >=1){
           if (action == 'i' || action == 'q' || action == 'w' ) {            // insert
                pthread_cond_signal(&cond);
						}
            else if (action == 'p') {     // wait
								while(endi==0);
								cout << "fdf"<< list.printList() << endl;
								endi = 0;
            }
            else {
                printf("ERROR: Unrecognized action: '%c'\n", action);
                exit(EXIT_FAILURE);
            }
				}
        else break;	
			}
		}
    for(i=0; i<N; i++) pthread_cancel(threads[i]);
    fclose(fin);
    clock_gettime( CLOCK_REALTIME, &stop);

    // print results
    cout << "Elapsed time: " << (stop.tv_sec - start.tv_sec) + ((double) (stop.tv_nsec - start.tv_nsec))/BILLION << " sec" << endl;

    // clean up and return
    return (EXIT_SUCCESS);

}
