#include <stdio.h>

#define MAX 100000

void input(int arr[], int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}

void merger(int arr[], int tmp[], int left, int mid, int right){
    int i = left, k = left;
    int j = mid + 1;

    while (i <= mid && j <= right){
        if (arr[i] <= arr[j]){
            tmp[k++] = arr[i++];
        }
        else tmp[k++] = arr[j++];
    }
    while (i <= mid){
        tmp[k++] = arr[i++];
    }
    while (j <= right){
        tmp[k++] = arr[j++];
    }
    for (int t = left; t <= right; t++){
        arr[t] = tmp[t];
    }
}

void mergerSort(int arr[], int tmp[], int left, int right){
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergerSort(arr, tmp, left, mid);
    mergerSort(arr, tmp, mid + 1, right);
    merger(arr, tmp, left, mid, right);
}

int mua(int arr[], int n, int money){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (money >= arr[i]){
            money -= arr[i];
            count++;
        }
        else break;
    }
    return count++;
}

int main (){
    int tmp[MAX];
    int n, money;
    scanf("%d%d", &n, &money);
    int arr[n];

    input(arr, n);
    mergerSort(arr, tmp, 0, n - 1);
    printf("%d", mua(arr, n, money));

    return 0; 
}
