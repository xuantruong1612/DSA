#include <stdio.h>

#define MAX 100000

int stack[MAX];
int top = -1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX - 1;
}

void push(int x){
    if(isFull()) return;
    stack[++top] = x;
}

int pop(){
    if(isEmpty()) return -1;
    return stack[top--];
}

void print(){
    for (int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void action(){
    int t; scanf("%d", &t);
    if (t == 1){
        pop();
    }
    if (t == 2){
        int x; scanf("%d", &x);
        push(x);
    }
}

int main (){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        action();
    }
    print();

    return 0;
}
