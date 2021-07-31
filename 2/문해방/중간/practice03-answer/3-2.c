#include <stdio.h>
#include <stdlib.h>


int main()
{
    char str[21];
    int i = 0;

    while(1){
        char ch = getchar();
        //char ch;
        //scanf("%c",&ch);
        if(ch == '\n' || i >= 20){
            break;
        }
        if( ch >= 65 && ch <= 90 ){
            continue;
        }else if((ch <= 122 && ch >= 97) || ch == 32){
            str[i++] = ch;
        }
    }

    str[i] = '\0';
    puts(str);

}
