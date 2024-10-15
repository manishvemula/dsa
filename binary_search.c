#include<stdio.h>
#define SIZE 9

int comp=0;
int binary_search(int arr[SIZE], int key, int l,int u);

int main(){
    int arr[SIZE]={11,22,33,44,55,66,77,88,99};
    int key;
    printf("enter the key");
    scanf("%d",&key);
    int res=binary_search(arr,key,0,SIZE-1);
    if(res==-1){
        printf("key not found");
    }
    else{
        printf("%d is index of key",res);
    }
    printf("comparisions=%d",comp);
    return 0;
}

int binary_search(int arr[SIZE],int key,int l,int u){
    while(l<=u){
        comp++;
        int mid=(l+u)/2;
        if(key==arr[mid]){
            return mid;
        }
        else{
            if(key<arr[mid]){
                u=mid-1;
            }
            else{
                l=mid+1;
            }
        } 
    }
    return -1;
}
  