#include <stddef.h>
#include <stdio.h>

#define MAX 100000

int front = 0, rear = -1;
int queue[MAX];

int isFull() { return rear == MAX - 1; }
int isEmpty() { return front > rear; }

void enqueue(int x) {
    if (isFull())
        return;
    queue[++rear] = x;
}

int dequeue() {
    if (isEmpty())
        return -1;
    return queue[front++];
}

void check() {
    int t;
    scanf("%d", &t);
    if (t == 1) {
        dequeue();
    } else if (t == 2) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        check();
    for (int i = front; i <= rear; i++)
        printf("%d", queue[i]);
}
