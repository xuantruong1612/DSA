#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
} node;

node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int x){
    if (root == NULL) return makeNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if(x > root->data) root->right = insert(root->right, x);
    return root;
}

void preorder(node *root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main (){
    node *root = NULL;
    int n; scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int x; scanf("%d", &x);
        root = insert(root, x);
    }
    preorder(root);

    return 0;
}
