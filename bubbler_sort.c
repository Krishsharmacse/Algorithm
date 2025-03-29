#include<stdio.h>
#include<stdlib.h>
#include <time.h>
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

void bubblesort(int arr[],int n){
    for(int i =0;i<n-1;i++){
        int swapped = 0;
        for(int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped++;
            }
        }
        if(swapped==0){
            break;
        }
    }
}
//O(n^2)
void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf(" "   "%d"   " ", arr[i]);
    }
    printf("\n");
    
}//O(n)
int main(){
    int n = 100; // Increase array size to 100000 elements
    int arr[n];

    // Initialize array with random values
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 999
    }
    printf("normal array\n");
    display(arr,n);
    clock_t start_time = clock();
    printf("sorted array\n");
    bubblesort(arr,n);
    display(arr,n);
    clock_t end_time = clock();
    double time_taken = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("Time taken for bubblesort is %9f",time_taken);
    return 0;
    //complexity of this code is O(n^2)
}