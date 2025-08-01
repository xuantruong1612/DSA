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
    int n, money;
    scanf("%d%d", &n, &money);
    int arr[n];
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, n - 1);
    
    int count = 0;
    for (int i = 0; i < n; i++){
        if (money >= arr[i]){
            money -= arr[i];
            count++;
        }
        else break;
        
    }
    printf ("%d", count);
    
    return 0;
}
