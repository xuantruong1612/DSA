#include <stdio.h>
#include <string.h>

#define MAX 100000

int ngoac(int open, int close){
    return (open == '(' && close == ')' || open == '[' && close == ']' || open == '{' && close == '}');
}

void push (char stack[], int *top, int u){
    if (*top == MAX - 1) return;
    stack[++(*top)] = u;
}

int pop(char stack[], int *top){
    if (*top == -1) return -1;
    return stack[(*top)--];
}

int check(char str[]){
    char stack[MAX];
    int top = -1;

    for (int i = 0; i < strlen(str); i++){
        char c = str[i];

        if (c == '(' || c == '{' || c == '['){
            push(stack, &top, c);
        }
        else if (c == ')' || c == '}' || c == ']'){
            if (top == -1) return 0;
            int open = pop(stack, &top);
            if (!ngoac(open, c)) return 0;
        }
    }
    return top == -1;
}

int main (){
    char input[MAX];
    scanf("%s", input);

    if (check(input)) printf("1");
    else printf("0");

    return 0;
}
