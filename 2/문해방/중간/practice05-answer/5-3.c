#include<stdio.h>

void main(){
    int n, x, t, sum;
    scanf("%d", &n);
    sum = 0;
    x = 0;
    t = 1;
    while(1){
        sum = sum +t;
        t = t*10;
        x++;
        if(sum % n ==0)
            break;
    }
    printf("%d",x);

}
