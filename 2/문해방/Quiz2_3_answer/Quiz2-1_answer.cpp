#include <iostream>
#include <stdio.h>

#define MAX 100

using namespace std;


bool finished = false;

int num;
int target;
int arr[MAX];
int menu;
int min_value = 1000000;
int min_count;
int min_sub_count[MAX][MAX];
int min_sub[MAX][MAX][MAX];
int index;
int subset_index;

bool is_a_solution(int a[], int k, int n){
    return (k == n);
}

void construct_candidates (int a[], int k, int n, int c[], int *n_can){
    c[0] = true;
    c[1] = false;
    *n_can = 2;
}

void process_solution (int a[], int k){
    int i;
    int sum = 0;
    if (menu == 1){
        printf("{");
        for (i=1; i<=k; i++)
            if (a[i] == true) printf(" %d", arr[i]);
        printf("}\n");
    }
    else if (menu == 2){
        for (i=1; i<=k; i++)
            if (a[i] == true) sum += arr[i];
        if (sum == target){
            printf("{");
            for (i=1; i<=k; i++)
                if (a[i] == true) printf(" %d", arr[i]);
            printf("}\n");
        }
    }
    else if (menu == 3){
        for (i=1; i<=k; i++)
            if (a[i] == true) sum += arr[i];
        if (target < sum)
            if (min_value > sum)
                min_value = sum;
        //printf("%d\n", min_value);
    }
    else if (menu == 4){
        for (i=1; i<=k; i++)
            if (a[i] == true) sum += arr[i];
        if (target < sum){
            if (min_value > sum){
                min_value = sum;
                min_count = 1;
                index++;
                subset_index = 1;
                for (i=1; i<=k; i++){
                    if (a[i] == true){
                        min_sub[index][min_count][subset_index++] = arr[i];
                        min_sub_count[index][min_count]++;
                    }
                }
            }
            else if (min_value == sum){
                min_count++;
                subset_index = 1;
                for (i=1; i<=k; i++){
                    if (a[i] == true){
                        min_sub[index][min_count][subset_index++] = arr[i];
                        min_sub_count[index][min_count]++;
                    }
                }
            }
        }
    }
}

void backtrack(int a[], int k, int n){
    int c[100];
    int n_can;
    int i;

    if (is_a_solution(a,k,n))
        process_solution (a,k);
    else {
        k = k + 1;
        construct_candidates (a, k, n, c, &n_can);
        for (i=0;i<n_can;i++){
            a[k] = c[i];
            backtrack (a, k, n);
            if (finished) return;
        }
    }
}

void generate_subsets (int n)
{
    int a[100];
    backtrack(a, 0, n);
}

int main()
{
    int i, j;

    printf("[Input]::# of Set component: ");
    scanf("%d", &num);

    printf("[Input]::Set: ");
    for (i=1; i<=num; i++)
        scanf("%d", &arr[i]);

    while (true){
        min_value = 100000;
        printf("\n1. Print out all subsets\n");
        printf("2. Print out all subsets whose sum is equal to a target value\n");
        printf("3. Print out minimum sum of subsets with exceeding a target value\n");
        printf("4. Print out all subsets whose sum is minimum value with exceeding a target value\n");
        printf("[Input]::Menu Select: ");
        scanf("%d", &menu);
        if (menu == 2 || menu == 3 || menu == 4){
            printf("[Input]::Target value: ");
            scanf("%d", &target);
        }
        printf("\n[Result]\n");
        generate_subsets (num);
        if (menu == 3){
            printf("%d", min_value);
        }
        else if (menu == 4){
            for (i=1;i<=min_count;i++){
                printf("{");
                for (j=1;j<=min_sub_count[index][i]; j++){
                    printf(" %d", min_sub[index][i][j], j, index, i);
                }
                printf("}\n");
            }
        }
        printf("\n\n");
    }
}
