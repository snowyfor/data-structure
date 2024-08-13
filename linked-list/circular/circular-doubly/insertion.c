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
struct Node *insertFront(struct Node *start, int value) {
    struct Node *newNode = createNode(value);
    //if the list is empty
    if(start == NULL) {
        newNode->next = newNode->prev = newNode;
        start = newNode;
        return;
    }

    //if list is not empty
    struct Node *last = start->prev;

    newNode->next = start;
    start->prev = newNode;
    last->next = newNode;
    newNode->prev = last;

    start = newNode;
    return start;
}
struct Node *insertEnd(struct Node *start, int value) {
    struct Node *newNode = createNode(value);
    //if the list is empty
    if(start == NULL) {
        newNode->next = newNode->prev = newNode;
        start = newNode;
        return;
    }

    //if list is not empty
    struct Node *last = start->prev;

    last->next = newNode;
    newNode->prev = last;
    newNode->next = start;
    start->prev = newNode;
}
//insert value after key node(ex insert 3 after node 5 will be <-5-><-3->)
struct Node *insertAfter(struct Node *start, int value, int key) {
    struct Node *newNode = createNode(value);
    //if the list is empty
    if(start == NULL) {
        printf("The list is empty\n");
        return;
    }

    //if list is not empty
    struct Node *curr = start;
    struct Node *afterCurr = start->next;
    while(1) {
        if(curr->data == key) {
            curr->next = newNode;
            newNode->prev = curr;
            newNode->next = afterCurr;
            afterCurr->prev = newNode;
            return;
        }
        curr = afterCurr;
        afterCurr = afterCurr->next;
        if(curr == start) break;
    }
}

int main() {
    // Create circular linked list: 1, 2, 3
    struct Node *node1 = createNode(1);
    struct Node *node2 = createNode(2);
    struct Node *node3 = createNode(3);

    node1->prev = node3;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node1;

    struct Node *start = node1;
    printList(start);
    start = insertFront(start, 0);  // 0 1 2 3
    start = insertEnd(start, 4);  // 0 1 2 3 4
    start = insertAfter(start, 5, 4);  // 0 1 2 3 4 5
    printList(start);

    return 0;
}