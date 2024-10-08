#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};
void printList(struct Node *start) {
    //if list is empty
    if (start == NULL) return;

    struct Node *temp = start;

    printf("\nTraversal in forward direction \n");
    while(temp->next != start) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);

    printf("\nTraversal in backward direction \n");
    struct Node *last = start->prev;
    temp = last;
    while(temp->prev != last) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

int main() {
    // Create circular linked list: 2, 3, 4
    struct Node *node1 = createNode(2);
    struct Node *node2 = createNode(3);
    struct Node *node3 = createNode(4);

    node1->prev = node3;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node1;

    printList(node1);

    return 0;
}