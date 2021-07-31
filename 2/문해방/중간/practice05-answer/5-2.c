#include<stdio.h>

void main(){

    int num1[10], num2[10];
    int i1, i2, d1, d2, carry, num_carries;
    char line[256];
    char *c;

    while(1){
        /* 입력 처리 */
        gets(line);
        i1 = 0; i2 =0;
        c = line;
        while (*c ==' ')
            c++;
        while (*c>= '0' && *c <= '9')
            num1[i1++] = *(c++) - '0';
        while (*c ==' ')
            c++;
        while (*c>= '0' && *c <= '9')
            num2[i2++] = *(c++) - '0';
        if (num1[0] == 0 && num2[0] == 0)
            break;
        num_carries = 0; carry = 0;
        i1--; i2--;

        /* 자리 올림 검사 */
        while (i1 >= 0 || i2 >= 0){
            d1 = (i1 >= 0 ? num1[i1]:0);
            d2 = (i2 >= 0 ? num2[i2]:0);
            if (d1 + d2 + carry >= 10){
                carry = 1;
                num_carries++;
            }
            else
                carry = 0;
            i1--; i2--;
        }

        printf("%d carry operations.\n", num_carries);
    }
}
