#include <stdio.h>
#include <stdlib.h>


int main()
{
    char str[21] = "THIS is string";
    char str2[21];

    printf("input compared string : ");
    gets(str2);

    int i = 0;
    int check = 0;
    while(str[i] != '\0'){
        if(str[i] == str2[i]){
            i++;
            continue;
        }else{
            i++;
            check = 1;
            break;
        }
    }

    puts(str);
    puts(str2);
    if(str2[i] == '\0' && check == 0){
        printf("Same!\n");
    }else{
        printf("Different!\n");
    }

}
