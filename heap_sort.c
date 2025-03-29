#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // To include clock() for measuring time
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

void heapify(int arr[], int index, int n) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&arr[largest], &arr[index]);
        heapify(arr, largest, n);
    }
}

void build_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
}

void heap_sort(int arr[], int n) {
    build_heap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[i], &arr[0]);
        heapify(arr, 0, i);
    }
}

void random_function(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000 + 1;
    }
}

int main() {
    int arr[100];
    int n=100;
    clock_t start, end;
    double time_taken;


    random_function(arr, n);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

  
    start = clock();

  
    heap_sort(arr, n);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    printf("Time taken for heap sort: %f seconds\n", time_taken);

    return 0;
}
