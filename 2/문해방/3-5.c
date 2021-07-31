#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getRandom(int *, int);
void bubbleSort(int *, int);
void swap(int *, int *);
void print(int *, int n);


void main(void)
{
	int n, *list, i;
	/* enter size of data array and prepare memory */
	printf("Enter size of array : ");
	scanf("%d", &n);
	list = (int *)malloc(sizeof(int)*n);

	if (!list) {
		fprintf(stderr, "Out of memory.\n");
		exit(1);
	}
	srand((unsigned int)time(NULL)); /* initialize random number generator */

	/* generate integer data by random number generation */
	printf("Generating data for bubble sort\n");
	getRandom(list, n);
	printf("generated data : ");
	print(list, n);

	/* bubble sort */
	printf("Starting bubble sorting\n");
	printf("sorted data : ");
	bubbleSort(list, n);
	print(list, n);

	return;
}


void getRandom(int *list, int n)
{
    int i;
    for(i=0; i<n; i++){
        list[i] = rand()%100;
    }

}

void bubbleSort(int *list, int n)
{
    int i,j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(list[j] > list[j+1])
                swap(&list[j],&list[j+1]);
        }
    }

}


void swap(int *left, int *right)
{
    int m;
    m = *left;
    *left = *right;
    *right = m;

}

void print(int *list, int n)
{
    int i;
    for(i=0; i<n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");

}
