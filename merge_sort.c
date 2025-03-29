#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
/*
Name - Krish Sharma
Enrollment Number =60416403224
course - B.Tech 
Branch - Computer Science and engineering

*/

void partition(int arr[], int p, int q, int r) {
    int l = q - p + 1;
    int m = r - q;
    int *a = (int *)malloc((l + 1) * sizeof(int));
    int *b = (int *)malloc((m + 1) * sizeof(int));

    for (int i = 0; i < l; i++) {
        a[i] = arr[p + i];
    }
    for (int j = 0; j < m; j++) {
        b[j] = arr[q + 1 + j];
    }

    int i = 0;
    int j = 0;
    a[l] = INT_MAX;
    b[m] = INT_MAX;
    int k = p;

    while (k <= r) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    free(a);
    free(b);
}

void mergesort(int arr[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergesort(arr, p, q);
        mergesort(arr, q + 1, r);
        partition(arr, p, q, r);
    }
}

void random_function(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100+ 1;
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

    mergesort(arr, 0, n - 1);


    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

 
    printf("Sorted array:\n");
    display(arr, n);

    printf("Time taken for merge sort: %f seconds\n", time_taken);

    return 0;
}
