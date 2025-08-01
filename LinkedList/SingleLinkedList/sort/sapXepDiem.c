#include <stdio.h>
#include <math.h>

typedef struct {
    int x, y;
    int index;
} Point;

int khoangCachBinhPhuong(Point p) {
    return p.x * p.x + p.y * p.y;
}

void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

int compare(Point a, Point b) {
    int da = khoangCachBinhPhuong(a);
    int db = khoangCachBinhPhuong(b);
    if (da != db)
        return da - db;
    return a.index - b.index;
}

int partition(Point arr[], int low, int high) {
    Point pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Point arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Point points[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].index = i;
    }

    quickSort(points, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    return 0;
}
