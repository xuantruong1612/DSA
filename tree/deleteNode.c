#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *makeNode (int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void NLR (node *root){
    if (root == NULL) return;
    printf("%d ", root->data);
    NLR(root->left);
    NLR(root->right);
}

void addNode(node **root, int x){
    if (*root == NULL) {
        *root = makeNode(x);
        return;
    }
    if ((*root)->data > x) addNode(&(*root)->left, x);
    else if ((*root)->data < x) addNode(&(*root)->right, x);
}

void getSuccessor (node *cur, node **succ){
    cur = cur->right;
    while (cur != NULL && cur->left != NULL){
        cur = cur->left;
    }
    *succ = cur;
}

void deleNode (node **root, int k){
    if (*root == NULL) return;
    if ((*root)->data > k) deleNode(&(*root)->left, k);
    else if ((*root)->data < k) deleNode(&(*root)->right, k);
    else {
        node *tmp = *root;
        if ((*root)->left == NULL){
            *root = (*root)->right;
            free(tmp);
        }
        else if ((*root)->right == NULL){
            *root = (*root)->left;
            free(tmp);
        }
        else {
            node *succ = NULL;
            getSuccessor(tmp, &succ);
            (*root)->data = succ->data;
            deleNode(&((*root)->right), succ->data);
        }
    }
}

int main()
{
    node *root = NULL;
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
        int x; scanf("%d", &x);
        addNode(&root, x);
    }
    deleNode(&root, k);
    
    NLR(root);
    
    return 0;
}
