#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
Name - Krish Sharma
Enrollment Number =60416403224
course - B.Tech 
Branch - Computer Science and engineering
*/

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r) {
    int index = p - 1;
    int pivot = arr[r];
    for (int i = p; i < r; i++) {
        if (arr[i] <= pivot) {
            index++;
            swap(&arr[i], &arr[index]);
        }
    }
    swap(&arr[r], &arr[index + 1]);
    return index + 1;
}

void quick_sort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}

void random_function(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int n=100;
    clock_t start, end;
    double time_taken;



    random_function(arr, n);

    
    printf("Original array:\n");
    display(arr, n);
    start = clock();
    quick_sort(arr, 0, n - 1);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  
    printf("Sorted array:\n");
    display(arr, n);

    printf("Time taken for quick sort: %f seconds\n", time_taken);

    return 0;
}
