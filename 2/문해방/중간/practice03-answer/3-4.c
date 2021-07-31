#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

void main(){
    char ch;
    int index = 0;
    char *m_string = (char*)malloc(sizeof(char)*(index+1));

    while((ch=getchar())!='\n'){
        m_string[index] = ch;
        index += 1;
        m_string = (char*)realloc(m_string, index+1);
    }
    m_string[index]='\0';

    printf("Length of str: %d\n", strlen(m_string));
    printf("content of str: %s\n", m_string);
}
