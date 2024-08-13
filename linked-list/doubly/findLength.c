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

void findLength(struct Node *head) {
    struct Node *current = head;

    int count = 0;
    while(current != NULL) {
        count++;
        current = current->next;
    }
}