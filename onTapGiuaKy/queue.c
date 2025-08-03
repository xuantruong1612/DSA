#include <stdio.h>

#define MAX 100000

void createQueue(int *front, int *rear, int *count){
    *front = 0;
    *rear = 0;
    *count = 0;
}

void enqueue(int arr[], int *rear, int *count,int x){
    if (*count == MAX) return;
    arr[*rear] = x;
    *rear = (*rear + 1) % MAX;
    (*count)++;
}

int dequeue(int arr[], int *front, int *count){
    if (*count == 0) return - 1;
    int tmp = arr[*front];
    *front = (*front + 1) % MAX;
    (*count)--;
    return tmp;
}

void print(int arr[], int front, int count){
    for (int i = 0; i < count; i++){
        int idx = (front + i) % MAX;
        printf("%d ", arr[idx]);
    }
    printf("\n");
}

void action(int arr[], int n, int *front, int *rear, int *count){
    for (int i = 0; i < n; i++){
    int t; scanf("%d", &t);
        if (t == 1){
            dequeue(arr, front, count);
        }
        if (t == 2){
            int x; scanf("%d", &x);
            enqueue(arr, rear, count, x);
        }    
    }
}


int main (){
    int n; scanf("%d", &n);
    int arr[n];
    int front, rear, count;
    createQueue(&front, &rear, &count);
    action(arr, n, &front, &rear, &count);
    print(arr, front, count);
}
