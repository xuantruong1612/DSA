#include <stdio.h>
#include <string.h>

#define MAX 10000

char stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (!isEmpty())
        return stack[top--];
    return '\0'; // Trả về ký tự null nếu rỗng
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int checkBrackets(char *expr) {
    top = -1; // reset stack
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty())
                return 0;
            char topChar = pop();
            if (!isMatching(topChar, c))
                return 0;
        }
    }
    return isEmpty();
}

int main() {
    char expr[MAX];
    printf("Nhap bieu thuc: ");
    fgets(expr, MAX, stdin);

    // Xoa newline neu co
    expr[strcspn(expr, "\n")] = 0;

    if (checkBrackets(expr))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}
