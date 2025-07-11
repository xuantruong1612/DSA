// windows khong ra ket qua, ubuntu error

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *makeNode (int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void print(node *head){
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void addTail(node **head, int val){
    node *newNode = makeNode(val);
    // if (*head == NULL){
    //     *head = newNode;
    // }
    
    // else {
        node *tmp = *head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    // }
}

int main(){
    node *head = NULL;
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        addTail(&head, val);
    }
    print(head);
    
    return 0;
}
