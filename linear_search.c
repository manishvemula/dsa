#include<stdio.h>
#define SIZE 9

int comp=0;
int linear_search(int arr[SIZE], int key);

int main(){
    int arr[SIZE]={11,22,33,44,55,66,77,88,99};
    int key;
    printf("enter the key");
    scanf("%d",&key);
    int res=linear_search(arr,key);
    if(res==-1){
        printf("key not found");
    }
    else{
        printf("%d is index of key",res);
    }
    printf("comparisions=%d",comp);
    return 0;
}

int linear_search(int arr[SIZE],int key){
    
    for(int i=0;i<SIZE;i++){
        if(arr[i]==key){
            return i;
        }
        comp++;
    }
    return -1;
}