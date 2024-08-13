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
struct Node *deleteNode(struct Node *start, int key) {
    //if the list is empty
    if(start == NULL) {
        printf("The list is empty");
        return;
    }

    //if only 1 node & it's the node we want to delete
    if(start->next == start && start->data == key) {
        free(start);
        return NULL;
    }

    //if >1 node
    struct Node *curr = start;
    while(1) {
        if(curr->data == key) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            if(curr == start) start = curr->next;  //if we delete the first node
            free(curr);
            return start;
        }
        curr = curr->next;
        if(curr == start) break;
    }
    return start;
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
    printList(start);  //1 2 3
    start = deleteNode(start, 2);
    printList(start);  //1 3

    return 0;
}