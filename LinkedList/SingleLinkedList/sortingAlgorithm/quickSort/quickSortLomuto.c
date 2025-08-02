#include <stdio.h>

void inputArr(int *arr, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}

void swap (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int l, int r){
    int pivot = arr[r]; // r = index arr end
    int i = l - 1; // i = -1
    for (int j = l; j < r; j++){
        if (arr[j] <= pivot){
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    ++i;
    swap(&arr[i], &arr[r]);
    return i;
}

void quickSort(int *a, int l, int r){
    if (l >= r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1); // left pivot;
    quickSort(a, p + 1, r); // right pivot;
}

int main (){
    int arr[1000], n;
    scanf("%d", &n);

    inputArr(arr, n);    
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
