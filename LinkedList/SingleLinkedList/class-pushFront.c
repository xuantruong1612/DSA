#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
node *makeNode(int x) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void pushFront(node **head, int x) { 
    node *newNode = makeNode(x);     
    newNode->next = *head; 
    *head = newNode;
}

int main() {
    node *head = NULL;
    int val;
    scanf("%d", &val);
    for (int i = 1; i < val; i++) {
        int x;
        scanf("%d", &x);
        pushFront(&head, x);
    }
    duyet(head);
    
    return 0;
}
