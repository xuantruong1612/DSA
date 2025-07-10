#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *makeNode(int x)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void print(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleTail(node **head)
{
    if (*head == NULL) return;
    else if ((*head)->next == NULL) {
        *head = NULL;
    }
    else
    {
        node *tmp = *head;
        while (tmp->next->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = NULL;
    }
}

int main()
{
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

    for (int i = 0; i < m; i++){
        deleTail(&head);
    }
    print(head);

    return 0;
}
