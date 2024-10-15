#include<stdio.h>
#define SIZE 6
#define SWAP(a,b) int temp=a; a=b; b=temp;

void selection_sort(int a[SIZE]);
void print(int arr[SIZE]);

int main(){
    int arr[SIZE]={44,22,99,66,44,88};
    printf("Array before sorted:\n");
    print(arr);
    printf("Array after sorted:\n");
    selection_sort(arr);
    print(arr);
    return 0;
}

void selection_sort(int a[SIZE]){
    for(int i=0;i<SIZE-1;i++){
        for(int j=i+1;j<SIZE;j++){
            if(a[i]>a[j]){
                SWAP(a[i],a[j]);
            }
        }
    }
}

void print(int arr[SIZE]){
    for(int i=0;i<SIZE;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
