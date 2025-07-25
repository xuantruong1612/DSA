// class


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

void enqueue(int Arr[], int x, int *front, int *end){
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
    for(int i = 0; i < n; i++){
        int action; scanf("%d", &action);
        if(action == 1){
            dequeue(Arr, &f, &e);
        }
        else if(action == 2){
            int u; scanf(" %d", &u);
            enqueue(Arr, u, &f, &e);
        }
    }
    
    
    return 0;
}
