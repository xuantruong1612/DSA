// class

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 3;
char A[MAX];
int top = -1;
int isempty()
{
    if (top == -1)
        return true;
    else
        return false;
}
int full()
{
    if (top == MAX - 1)
        return true;
    else
        return false;
}
void push(char x)
{
    if (!full())
    {
        top++;
        A[top] = x;
    }
}
char pop()
{
    if (!isempty())
    {
        char tmp = A[top];
        top--;
        return tmp;
    }
    return '-';
}
void printStack()
{
    for (int i = 0; i <= top; i++)
        printf("%c ", A[i]);
}
int kiemtra(char BB[])
{
    int n = strlen(BB);
    for (int i = 0; i < n; i++)
    {
        if (BB[i] == '(' || BB[i] == '[' || BB[i] == '{')
        {
            push(BB[i]);
        }
        else if (BB[i] == ')' || BB[i] == ']' || BB[i] == '}')
        {
            char uu = pop();
            if (uu == '-')
                return 0;
            else
            {
                if (BB[i] == ')' && uu != '(')
                    return 0;
                if (BB[i] == ']' && uu != '[')
                    return 0;
                if (BB[i] == '}' && uu != '{')
                    return 0;
            }
        }
    }
    if (isempty())
        return 1;
    else
        return 0;
}
int main()
{
    char BT[10000];
    scanf("%s", BT);
    printf("%d", kiemtra(BT));
}

-----------------------------------------------------------
  
#include <stdio.h>

#define MAX 100000

int queue[MAX];

int isEmpty(){ return front > end;}

int isFull(){ return end == MAX - 1;}

void createQueue(int *front, int *end, int *count){
    *front = 0;
    *end = -1;
    *count = 0;
}

void enqueue(int x, int Arr[], int *front, int *end){
    if(*count < MAX){
        if (isFull()){
            *end = 0;
        }
        else (*front)++;
        (*count)++;
    }
    else printf("Queue Full");
}

int dequeue(int Queue[], int *end, int count){
    if(count != 0){
        int tmp = Arr[*end];
        if (*end == MAX - 1){
            *end= 0;
        }
        else (*end)++;
        count--;
        return tmp;
    }
    else {
        printf ("Queue Empty");
        return -1;
    }
}

int printQueue(int Arr[], int front, int count){
    for(int i = 0; i < count; i++){
        
    }
}

int main(){
    int Arr[MAX];
    int f, e, c, n;
    createQueue(&f, &e, &c);
    enqueue()
    
    
    return 0;
}
