#include<stdio.h>

int comp=0;
int linear_search(int arr[],int SIZE, int key);

int main(){
    int arr[]={11,22,33,44,55,66,77,88,99};
    int key;
    printf("enter the key");
    scanf("%d",&key);
    int res=linear_search(arr,sizeof(arr)/sizeof(arr[0]),key);
    if(res==-1){
        printf("key not found");
    }
    else{
        printf("%d is index of key",res);
    }
    printf("comparisions=%d",comp);
    return 0;
}

int linear_search(int arr[],int SIZE,int key){
    
    if(SIZE==0){
        return -1;
    }
    comp++;
    if(arr[SIZE-1]==key){
        return SIZE-1;
    }
    return linear_search(arr,SIZE-1,key);
}
