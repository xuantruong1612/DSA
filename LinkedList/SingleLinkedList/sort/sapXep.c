#include <stdio.h>

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            int temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    int temp = a[i + 1]; a[i + 1] = a[high]; a[high] = temp;
    return i + 1;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[1000005];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
