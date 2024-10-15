#include<stdio.h>
#define SIZE 6

void insertion_sort(int a[SIZE]);
void print(int arr[SIZE]);

int main(){
    int arr[SIZE]={44,22,99,66,44,88};
    printf("Array before sorted:\n");
    print(arr);
    printf("Array after sorted:\n");
    insertion_sort(arr);
    print(arr);
    return 0;
}

void insertion_sort(int a[SIZE]){
    for(int i=0;i<SIZE;i++){
        int temp=a[i];
        /**int j;
        for(j=i-1;j>=0 && temp<a[j];j--){
            a[j+1]=a[j];
        }**/
       int j=0;
       while(j>=0 && temp<a[j]){
        a[j+1]=a[j];
        j--;
       }
        a[j+1]=temp;
    }
}

void print(int arr[SIZE]){
    for(int i=0;i<SIZE;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
