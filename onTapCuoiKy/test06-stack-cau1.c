#include <stdio.h>

#define MAX 100

void push(int stack[], int *top, int u) {
    if (*top < MAX - 1) {
        stack[++(*top)] = u;
    }
}

int pop(int stack[], int *top) {
    if (*top == -1) return -1;
    return stack[(*top)--];
}

void printTop(int stack[], int top) {
    if (top == -1) {
        printf("Empty!\n");
    } else {
        printf("%d\n", stack[top]);
    }
}

void action(int stack[], int *top, int n) {
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int u;
            scanf("%d", &u);
            push(stack, top, u);
        } else if (t == 2) {
            pop(stack, top);
        } else if (t == 3) {
            printTop(stack, *top);
        }
    }
}

int main() {
    int n, top = -1;
    int stack[MAX];

    scanf("%d", &n);
    action(stack, &top, n);

    return 0;
}
