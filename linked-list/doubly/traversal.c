#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
};

void forwardTraversal(struct Node *head) {
    struct Node *current = head;

    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void backwardTraversal(struct Node *tail) {
    struct Node *current = tail;

    while(current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}