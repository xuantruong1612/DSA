#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int data;
    struct node *next;
};

node *makeNode(int val) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int count(node *head) {
    int dem = 0;
    while (head != NULL) {
        dem++;
        head = head->next;
    }
    return dem;
}

void pushFront(node **head, int val) {
    node *newNode = makeNode(val);
    newNode->next = *head;
    *head = newNode;
}

int main (){
    node *head = NULL;
    for (int i = 1; i <= 5; i++){
        pushFront(&head, i);
    }
    duyet(head);
    printf("\n%d", count(head));
}
