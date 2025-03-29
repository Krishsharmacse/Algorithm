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
void insertion_sort(int arr[],int n){
    for(int i =1;i<n;i++){
        for(int j =i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(&arr[j],&arr[j-1]);
            }
        }
    }

}

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf(" " "%d" " ", arr[i]);
    }
    printf("\n");
    
}
int main(){
    int n = 100; // Increase array size to 100000 elements
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 999
    }
    printf("unsorted array\n");
    display(arr,n);
    clock_t start_time = clock();

    printf("sorted array\n");
    insertion_sort(arr,n);
    display(arr,n);
    clock_t end_time = clock();
    double time_taken = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time taken for insertion sort is %9f",time_taken);
    return 0;
}