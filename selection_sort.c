#include<stdio.h>
#include<time.h>
#include<stdlib.h>
/*
Name - Krish Sharma
Enrollment Number =60416403224
course - B.Tech 
Branch - Computer Science and engineering
Subject - Computational Methods
*/

void swap(int* a , int* b){
    int temp= *a;
    *a=*b;
    *b=temp;
}
void min_selection_sort(int arr[],int n){
    for(int i =0;i<n-1;i++){
        int min_idx=i;
        for(int j = i+1;j<n;j++){
            if(arr[min_idx]>arr[j]){
            min_idx =j;
            }
        }
        if(min_idx!=i){
            swap(&arr[i],&arr[min_idx]);
        }
    }
}
//due to nested for loops time complexity become O(n^2)
void max_selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(&arr[max_idx], &arr[i]);
        }
    }
}


void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf(" "   "%d"   " ", arr[i]);
    }
    printf("\n");
    
}
int main(){
    int n = 100000; 
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; 
    }
  
    clock_t start_time = clock();
    printf("sorted array\n");
    min_selection_sort(arr,n);
    display(arr,n);
    clock_t end_time = clock();
    double time_taken = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time taken for selection sort is %9f",time_taken);
    return 0;
    //Time complexity for selection sort is O(n^2)
    
}