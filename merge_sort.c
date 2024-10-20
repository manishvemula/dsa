#include<stdio.h>
#include<stdlib.h>
#define SIZE 9

void merge_sort(int arr[SIZE],int left, int right);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    printf("\n Before Sort :\n");
    display(arr);
    printf("\n After Sort :\n");
    merge_sort(arr,0,SIZE-1);
    display(arr);
    return 0;
}

void merge_sort(int arr[SIZE],int left, int right){
    if(left>=right){
        return;
    }
    int mid=(left+right)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);

    int temp_size=right-left+1;
    int *temp=(int *)malloc(sizeof(int)*temp_size);

    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=right){
    if(arr[i]<arr[j]){
        temp[k]=arr[i];
        i++;
        k++;
    }
    else{
        temp[k]=arr[j];
        j++;
        k++;
    }
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=right){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int i=0;i<temp_size;i++){
        arr[left+i]=temp[i];
    }
    free(temp);
    temp=NULL;
    
}

void display(int arr[SIZE])
{
    for(int i =0; i<SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}