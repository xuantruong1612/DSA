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

int count(node *head) {
    int dem = 0;
    while (head != NULL) {
        ++dem;
        head = head->next;
    }
    return dem;
}

// pushFornt nay la truyen tham tri
void pushFront(node **head, int x) { // **head: pointer pointer head
    node *newNode = makeNode(x);     // *newNode: node pointer type
    // buoc 1: next cua newNode -> head
    newNode->next = *head; // *head: toan tu dai tham chieu (addess: node head)
    // buoc 2: cap nhat node head->newNode
    *head = newNode;
}

int main() {
    node *head = NULL;
    for (int i = 1; i <= 5; i++) {
        pushFront(&head, i); // **head nen phai goi &head
    }
    duyet(head);
    printf("\n%d ", count(head));
    return 0;
}
