#include <stdio.h>

#define MAX 100000

void createQueue(int *front, int *rear, int *count){
    *front = 0;
    *rear = 0;
    *count = 0;
}

void enqueue(int *rear, int *count, int arr[], int x){
    if (*count == MAX) return; //full
    arr[*rear] = x;
    *rear = (*rear + 1) % MAX;
    (*count)++;
}

int dequeue(int *front, int *count, int arr[]){
    if (*count == 0) return -1; // empty
    int tmp = arr[*front];
    *front = (*front + 1) % MAX;
    (*count)--;
    return tmp;
}

void printQueue(int front, int count, int arr[]){
    for (int i = 0; i < count; i++){
        int idx = (front + i) % MAX;
        printf("%d ", arr[idx]);
    }
    printf("\n");
}

void action(int *front, int *rear, int *count, int arr[]){
    int t; scanf("%d", &t);
    if (t == 1) dequeue(front, count, arr);
    else if (t == 2) {
        int x; scanf("%d", &x);
        enqueue(rear, count, arr, x);
    }
}

int main (){
    int arr[MAX], n, f, r, c;
    scanf("%d", &n);

    createQueue(&f, &f, &c);

    for (int i = 0; i < n; i++)
        action(&f, &r, &c, arr);

    printQueue(f, c, arr);

    return 0;
}
