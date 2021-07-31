#include<stdio.h>

void print(int *arr,int len){
    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void right_rotate(int *arr, int s, int e){
    int l=arr[e];
    for(int i=e;i>s;i--)
        arr[i]=arr[i-1];
    arr[s]=l;
}

void left_rotate(int *arr, int s, int e){
    int f=arr[s];
    for(int i=s;i<e;i++)
        arr[i]=arr[i+1];
    arr[e]=f;
}

void perm(int *arr, int len, int n, int k){
    if(len==k){
        print(arr,k);
        return;
    }
    for(int i=len;i<n;i++){
        right_rotate(arr,len,i);
        printf("aa");
        print(arr,n);
        perm(arr,len+1,n,k);
        printf("bb");
         print(arr,n);
        left_rotate(arr,len,i);
        printf("cc");
         print(arr,n);
    }
}

int main(){
    int arr[10];
    int n,k;
    printf("Input number n, k : ");
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        arr[i]=i+1;
    perm(arr,0,n,k);
    return 0;
}

