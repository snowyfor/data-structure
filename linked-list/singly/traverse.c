#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//traverseLoop == printList at insertion & deletion
struct Node *traverseLoop(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct Node *traverseRecursive(struct Node *head) {
    if(head == NULL) {
        printf("\n");
        return NULL;
    }

    printf("%d ", head->data);
    traverseRecursive(head->next);
}

int main() {
    // Create the linked list 1->2->3->4->5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    traverseLoop(head);
    head->next->next->next->next = createNode(5);
    traverseRecursive(head);
}