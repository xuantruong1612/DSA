#include <stdio.h>

#define max 2

void enqueue (char queue[], int *f, int *e, int *c, int u){
    if (*c == max){
        *f = (*f + 1) % max;
        (*c)--;
    }
    queue[*e] = u;
    *e = (*e + 1) % max;
    (*c)++;
}

void print(char queue[], int f, int c){
    for (int i = c - 1; i >= 0; i--){
        int idx = (f + i) % max;
        printf("%c ", queue[idx]);
    }
}

int main (){
    char queue[max];
    int n, f = 0, e = 0, c = 0; 
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        char u; scanf(" %c", &u);
        enqueue(queue, &f, &e, &c, u);
    }
    print(queue, f, c);

    return 0;
}
