#include<stdio.h>

unsigned long fact[14];

void main(){
    unsigned long answer;
    int n, k, n_i, i;

    fact[0] = 1;
    for (i=1; i<=13; i++)
        fact[i] = fact[i-1] * i;
    scanf("%d %d", &n, &k);
    answer = fact[n];
    for (i = 0; i < k; i++){
        scanf("%d", &n_i);
        if (n_i > 1){
            answer /= fact[n_i];
        }
    }
        printf("%lu\n", answer);

}
