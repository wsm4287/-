#include<stdio.h>

int strLen(char *str){
    int len = 0;

    while(str[len]!='\0')
        len++;

    return len;
}

void main(){

    char str1[100];
    char str2[100];
    int i = 0;
    int len = 0;

    printf("[Input]::Enter first string: ");
    scanf("%s", str1);
    printf("[Input]::Enter second string: ");
    scanf("%s", str2);

    len = strLen(str1);

    while(str2[i]!='\0'){
        str1[len+i] = str2[i];
        i++;
    }

    str1[len+i] = '\0';
    printf("After concatenation: %s\n", str1);
}
