#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *makeNode(int val) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        head = temp->next;
    }
    printf("NULL");
}

int count (node *head){
    node *dem = head;
    while (head != NULL){
        dem++;
        head = head->next;
    }
}

int main(){
    node *head = NULL;
}
