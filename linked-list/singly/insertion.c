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
void printList(struct Node *head) {
    struct Node *current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node *insertAtFront(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    
    newNode->next = head;
    return newNode;
}
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);

    if(head == NULL) {
        return newNode;
    }

    struct Node *last = head;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;

    return head;
}
struct Node *insertAfter(struct Node *head, int key, int newData) {
    struct Node *current = head;
    while (current != NULL) {
        if(current->data == key)
            break;
        current = current->next;
    }

    if(current == NULL) {
        return head;
    }

    struct Node *newNode = createNode(newData);
    newNode->next = current->next;
    current->next = newNode;

    return head;
}
struct Node *insertAtPosition(struct Node *head, int position, int data) {
    struct Node *newNode = createNode(data);
    
    if(position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node *current = head;
    for(int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if(current == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main() {
    // Create the linked list 10->20->30
    struct Node *node1 = createNode(1);
    struct Node *node2 = createNode(2);
    struct Node *node3 = createNode(3);

    node1->next = node2;
    node2->next = node3;

    printList(node1);

    // Create the linked list 2->3->5->6
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(5);
    head->next->next->next = createNode(6);

    int data = 1;
    head = insertAtFront(head, data); //1->2->3->5->6
    head = insertAtEnd(head, 7); //1->2->3->5->6->7
    int dataa = 12, pos = 4;
    head = insertAtPosition(head, pos, dataa); //1->2->3->12->5->6->7
    int key = 12, newData = 4;
    head = insertAfter(head, key, newData); //1->2->3->12->4->5->6->7
    printList(head);


    free(node1);
    free(node2);
    free(node3);

    return 0;
}