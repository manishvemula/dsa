#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
#define SWAP(a,b) int temp=a; a=b; b=temp;

void bubble_sort(int a[SIZE]);
void print(int arr[SIZE]);

int main(){
    int arr[SIZE]={44,22,99,66,44};
    int *p=(int *)malloc(SIZE*sizeof(int));
    printf("Array before sorted:\n");
    print(arr);
    printf("Array after sorted:\n");
    bubble_sort(arr);
    print(arr);
    free(p);
    return 0;
}

void bubble_sort(int a[SIZE]){
    for(int i=0;i<SIZE-1;i++){
        for(int j=0;j<SIZE-1;j++){
            if(a[j]>a[j+1]){
                SWAP(a[j],a[j+1]);
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
