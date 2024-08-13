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
};
void printList(struct Node *last) {
    if (last == NULL) return;

    struct Node *head = last->next;
    while (1) {
        printf("%d ", head->data);
        head = head->next;
        if (head == last->next) break;
    }
    printf("\n");
}

struct Node *insertInEmptyList(struct Node* last, int data) {
    if (last != NULL) return last;

    struct Node* newNode = createNode(data);

    last = newNode;
    return last;
}
struct Node *insertFront(struct Node* last, int data) {
    struct Node *newNode = createNode(data);
    if(last == NULL) {
        newNode->next = newNode;
        return newNode;
    };

    newNode->next = last->next;
    last->next = newNode;
    return last;
}
struct Node *insertEnd(struct Node* last, int data) {
    struct Node *newNode = createNode(data);
    if(last == NULL) {
        last = newNode;
        newNode->next = newNode;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last; 
}
struct Node *insertAtPosition(struct Node *last, int data, int position) {
    struct Node *newNode = createNode(data);

    if(last == NULL) {
        if(position != 1) {
            printf("invalid position due to empty list");
            return last;
        }

        last = newNode;
        last->next = last;
        return last;
    }

    struct Node *curr = last->next;
    if(position == 1) {
        newNode->next = curr;
        last->next = newNode;
        return last;
    }

    for(int i = 1; i < position - 1; i++) {
        curr = curr->next;

        if(curr == last->next) {
            printf("Invalid position!\n");
            return last;
        }
    }
    newNode->next = curr->next;
    curr->next = newNode;

    if(curr == last) last = newNode;
    return last;
}

int main() {
    // Create circular linked list: 2, 3, 4
    struct Node *first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);

    struct Node *last = first->next->next;
    last->next = first;

    printList(last);  // 2 3 4
    last = insertFront(last, 1);  
    printList(last);  // 1 2 3 4
    last = insertEnd(last, 7);
    printList(last);  // 1 2 3 4 7
    last = insertAtPosition(last, 5, 5);
    printList(last);  // 1 2 3 4 5 7
    last = insertAtPosition(last, 6, 6);
    printList(last);  // 1 2 3 4 6 7

    return 0;
}