#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// node la pointer quan li node khac (node = pointer node)
typedef struct node node;
/* struct node *makeNode(int x) {
     struct node *newNode = (struct node*)malloc(sizeof(struct node));
    */
node *makeNode(int x) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
