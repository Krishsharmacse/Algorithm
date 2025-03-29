#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <time.h>
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//The swap function is an O(1) operation, as it only swaps two variables in constant time.
int partition(int arr[],int p, int r){
    int i = p-1;
    int pivot = arr[r];
    for(int j =p;j<r;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
            
        } 
    }
        swap(&arr[i+1],&arr[r]);
        return i+1;
}
//for partition function O(n).

void quicksort( int arr[], int p, int r){
    if(p<r){
       int q = partition(arr, p, r); 
    
    quicksort(arr,p,q-1);
    quicksort(arr,q+1,r);
    }
}//Average Case Time Complexity: O(n log n)
// the worst-case is O(n²)
int Binary_search(int arr[],int start, int end,int key){
  
    while (start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if (arr[mid]>key)
        {
            end = mid -1;
        }
        else{
        start = mid +1;
        }
        
    }
    
}
//Time complexity for binary search : (logn)
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}//O(n)
void random_function(int arr[],int n){
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000 + 1;  
    }
}//O(n)
int main(){
    int arr[100000];
    int key;
    int n = sizeof(arr)/sizeof(arr[0]);
    random_function(arr,n);
    display(arr,n);
    
    printf("the size is " "%d\n",n);
printf("Enter the key for search ");
    scanf("%d", &key);
    quicksort(arr,0,n-1); // O(n log n) (Average case)

    printf("Sorted Array:\n");
         clock_t start_time = clock();  // Start time
    display(arr, n);


    printf("%d\n",Binary_search(arr,0,n-1,key));// O(log n)
     clock_t end_time = clock();    // End time
     double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;  // Calculate elapsed time
     printf("Time taken to Binary search: %f seconds\n", time_taken);
     printf("Your seaching element is %d",key);

    return 0;
    //the total time complexity of the code is dominated by the sorting step (quicksort) and is O(n log n) in the average case.
    //Worst Case Time Complexity: O(n²) (due to worst-case behavior of quicksort)
    //for best case total time complexity is O(logn)
    
}