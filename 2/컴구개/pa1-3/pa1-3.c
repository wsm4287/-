# include <stdio.h>
# define MAX_SIZE 100
# define BUF_SIZE 1000

int list[MAX_SIZE] = {0};

void swap (int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int left, int right){
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left]; 

    do{
        do {
            low++; 
        } while (low<=right && list[low]<pivot);
        do {
            high--; 
        } while (high>=left && list[high]>pivot);
        if(low<high){
            swap(&list[low], &list[high]);
        }
    } while (low<high);
    swap(&list[left], &list[high]);

    return high;
}

void quick_sort(int left, int right){
    if(left<right){
        int q = partition(left, right);
        quick_sort(left, q-1); 
        quick_sort(q+1, right); 
    }
}

void main(){
    int i = 0;
    FILE *fd;
    int cursor = 0;
    int n = 0;
    char buffer[BUF_SIZE];

    fd = fopen("pa1-3.input", "r");
	fread(buffer, sizeof(char), sizeof(buffer), fd);
	fclose(fd);

    while(1){
        while(buffer[cursor] != ' ' && buffer[cursor] != '\n'){
            list[n] *= 10;
            list[n] += buffer[cursor] - '0';
            cursor++;
        }
        n++;
        if(buffer[cursor++] == '\n') break;
    }

    quick_sort(0, n-1);

    for(i=0; i<n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}
