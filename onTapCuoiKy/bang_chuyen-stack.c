#include <stdio.h>

#define max 10

void push (int stack[], int *top, int u){
    if (*top == max - 1){
        for (int i = *top; i > 0; i--){
            stack[i] = stack[i - 1];
        }
        stack[0] = u;
    }
    else stack[++(*top)] = u;
}

void print(int stack[], int top){
    for (int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
}

int main (){
    int n, top = -1;
    scanf("%d", &n);
    int stack[max];
    
    for (int i = 0; i < n; i++){
        int u; scanf("%d", &u);
        push(stack, &top, u);
    }
    print(stack, top);

    return 0;
}
