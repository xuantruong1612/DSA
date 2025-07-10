#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *makeNode (int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void print(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void deleMid(node **head, int flag){
    if (*head == NULL) return;
    node *tmp = *head;

    while (tmp != NULL && tmp->data != flag){
        tmp = tmp->next;
    }

    if (tmp != NULL && tmp->next != NULL){
        node *toDel = tmp->next;
        tmp->next = toDel->next;
        free(toDel);
    }
}

int main (){
    node *head = NULL;
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        node *newNode = makeNode(x);
        newNode->next = head;
        head = newNode;
    }

    for (int i = 0; i < m; i++) {
        int b;
        scanf("%d", &b);
        deleMid(&head, b);
    }

    print(head);
    
}
