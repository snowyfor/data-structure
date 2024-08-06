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

struct Node *insertFront(struct Node *head, int data) {
    struct Node *newNode = createNode(data);

    if(head == NULL) return newNode;

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}
struct Node *insertEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);

    if(head == NULL) return newNode;

    struct Node *last = head;
    while(last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
    return head;
}
struct Node *insertAtPosition(struct Node *head, int data, int position) {
    struct Node *newNode = createNode(data);

    if(head == NULL) {
        return (position == 1) ? newNode : head;
    }

    if(position == 1) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    struct Node *current = head;
    for(int i = 1; i < position - 1 && head != NULL; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    newNode->prev = current;
    return head;
}

int main() {
    // Create an empty list
    struct Node* head = NULL;

    head = insertFront(head, 1);
    head = insertAtPosition(head, 22, 2);
    head = insertEnd(head, 3);
    
    // Menampilkan data dalam linked list(dari depan)
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}