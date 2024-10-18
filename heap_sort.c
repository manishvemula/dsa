#include<stdio.h>

#define SWAP(a,b) int temp=a;a=b;b=temp;
int size=10;

void make_heap(int arr[]);
int delete_max(int arr[]);
void display(int arr[]);
void heap_sort(int arr[]);

int main(){
    int arr[11] = {0,20,12,35,15,10,80,30,17,2,1};
    printf("\n input array\n:");
    display(arr);

    make_heap(arr);
    printf("\n input array-make_heap\n:");
    display(arr);
    
    heap_sort(arr);
    printf("\n sorted array-heap_sort\n:");
    display(arr);
    return 0;
}

void make_heap(int arr[]){
    for(int i=size/2;i>=1;i--){
        int ci=i*2;
        while(ci<=size){
            int pi=ci/2;
            if((ci+1)<=size && arr[ci+1]>arr[ci]){
                ci=ci+1;
            }
            if(arr[pi]>arr[ci]){
                break;
            }
            else{
            int temp=arr[ci];
            arr[ci]=arr[pi];
            arr[pi]=temp;
            }
            ci=ci*2;
        }
    }
}

int delete_max(int arr[]){
    int max=arr[1];
    arr[1]=arr[size];
    arr[size]=max;
    size--;
    int ci=1*2;
    while(ci<=size){
        int pi=ci/2;
        if((ci+1)<=size && arr[ci+1]>arr[ci]){
            ci=ci+1;
        }
        if(arr[pi]>arr[ci]){
            break;
        }
        else{
        int temp=arr[ci];
        arr[ci]=arr[pi];
        arr[pi]=temp;
        }
        ci=ci*2;
    }    
    return max;
}

void display(int arr[]){
    for(int i=1;i<11;i++){
        printf("%4d",arr[i]);
    }
    printf("\n");
}

void heap_sort(int arr[]){
    make_heap(arr);
    for(int i=1;i<11;i++){
        delete_max(arr);
    }
}