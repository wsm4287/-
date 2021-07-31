#include<stdio.h>
#include<math.h>

int solve(int n){
    int i;
    int sum = 0;

    if (n == 0) return 0;

    for (i = 1; sum < n; i++){
        sum += ceil((double)i/2);
    }
    return i-1;
}

void main(){
    int loop, i;
    int x, y;

    printf("Input # of Test: ");
    scanf("%d", &loop);

    for (i = 0; i< loop; i++){
        printf("[[Test Case %d]]\n", i);
        printf("Input x and y (ex. 2 3): ");
        scanf("%d %d", &x, &y);

        printf("Answer: %d\n", solve(y-x));
    }
}
