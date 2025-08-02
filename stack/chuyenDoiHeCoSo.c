#include <stdio.h>

#define MAX 10000

int top = -1;
int stack[MAX];

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX - 1;
}

void push (int x){
    if (isFull()) return;
    stack[++top] = x;
}

int pop (){
    if (isEmpty()) return -1;
    return stack[top--];
}

void chuyenDoi(int n, int heSo){
    top = -1;

    while (n != 0){
        push(n % heSo);
        n /= heSo;
    }
}

void hienThi(){
    while(!isEmpty()){
        int tmp = pop();
        if (tmp < 10) printf("%d ", tmp);
        else printf("%c ", tmp - 10 + 'A');
    }
} 

int main (){
    int t;
    scanf("%d", &t);
    while (t--){
        int n; scanf("%d", &n);
        int heSo; scanf("%d", &heSo);
        printf("so %d cua he so %d la: ", n, heSo);
        chuyenDoi(n, heSo);
        hienThi();
    }

    return 0;
}
