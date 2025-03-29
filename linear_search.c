#include <stdio.h>
int linear_search(int arr[], int n, int key){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==key){
            return i;

        }
    }
    return -1;
}
int main(){
    int arr[]={12,32,4,565,78,98,41,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d",linear_search(arr,n,78));
    return 0;


}