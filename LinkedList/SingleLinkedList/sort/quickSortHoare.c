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

// Hoare partition function
int partition(int *arr, int l, int r){
    int pivot = arr[l];
    int i = l - 1;
    int j = r + 1;

    while (1){
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void quickSort(int *a, int l, int r){
    if (l < r){
        int p = partition(a, l, r);
        quickSort(a, l, p);
        quickSort(a, p + 1, r);
    }
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
