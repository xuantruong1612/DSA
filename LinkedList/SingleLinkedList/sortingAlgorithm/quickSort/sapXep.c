#include <stdio.h>

void swap (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition (int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++){
        if (arr[j] <= pivot){
            ++i;
            swap (&arr[i], &arr[j]);
        }
    }
    ++i;
    swap(&arr[i], &arr[r]);
    return i;
}

void quickSort(int arr[], int l, int r){
    if (l >= r) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
}

int main (){
    int n; scanf("%d", &n);
    int arr[n];
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++){
        printf ("%d ", arr[i]);
    }
    
    return 0;
}
