#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool searchLoop(struct Node *head, int key) {
    while(head != NULL) {
        if(head->data == key) return true;
        head = head->next;
    }
    return false;
}
bool searchRecursive(struct Node *head, int key) {
    if(head == NULL) return false;

    if(head->data == key) return true;
    searchRecursive(head->next, key);
}

int main() {
    // Create the linked list 1->2->3->4->5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    if(searchLoop(head, 3)) {
        printf("Found!\n");
    } else {
        printf("Not found!\n");
    }

    if (searchRecursive(head, 5)) {
        printf("Found!\n");
    } else {
        printf("Not Nound!\n");
    }
}