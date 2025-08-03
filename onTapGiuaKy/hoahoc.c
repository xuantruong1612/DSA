#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100000

int kl(char ngto){
    if (ngto == 'C') return 12;
    if (ngto == 'H') return 1;
    if (ngto == 'O') return 16;
    return 0;
}

void push (int stack[], int *top, int u){
    if (*top == MAX - 1) return;
    stack[++(*top)] = u;
}

int pop (int stack[], int *top){
    if (*top == -1) return -1;
    return stack[(*top)--];
}

int isElement(char c){
    return (c == 'H' || c == 'O' || c == 'C');
}

int check(char str[]){
    int stack[MAX], top = -1;

    for (int i = 0; i < strlen(str); i++){
        char c = str[i]; 

        if (c == '('){
            push(stack, &top, -1);
        }
        else if (isElement(c)){
            push(stack, &top, kl(c));
        }
        else if (c == ')'){
            int sum = 0;
            while (top != -1 && stack[top] != -1){
                sum += pop(stack, &top);
            }
            pop(stack, &top);
            push(stack, &top, sum);
        }
        else if (isdigit(c)){
            int num = c - '0';
            int val = pop(stack, &top);
            push(stack, &top, val * num);
        }
    }

    int total = 0;
    while (top != -1){
        total += pop(stack, &top);
    }
    return total;
}

int main (){
    char str[MAX];
    scanf("%s", str);
    printf("%d", check(str));
}

