#include <stdio.h>

#define MAX 100000

void inoder(int arr[], int n, int i){
    if (i >= n || arr[i] == -1) return;
    inoder(arr, n, 2 * i + 1);
    printf("%d ", arr[i]);
    inoder(arr, n, 2 * i + 2);
}

int main (){
    int n; scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    inoder(arr, n, 0);

    return 0;
}
