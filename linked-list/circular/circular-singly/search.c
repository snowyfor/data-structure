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

int search(struct Node *last, int key) {
    if (last == NULL) return 0;  //if the list is empty

    struct Node *head = last->next;
    struct Node *curr = head;

    while(1) {  //traverse the list to find the key
        if(curr->data == key) {
            return 1;  //key found
        }
        curr = curr->next;

        if(curr == head) break;  //jika balik lagi ke head berarti sudah iterasi dari awal sampai akhir
    }

    return 0;  //key not found
}
int search2(struct Node *last, int key) {
    if (last == NULL) return 0;  //tf the list is empty

    struct Node *head = last->next;
    struct Node *curr = head;

    while(curr != last) {  //traverse the list to find the key
        if(curr->data == key) {
            return 1;
        }
        curr = curr->next;
    }

    if(last->data == key) return 1;  //check the last node
    return 0;
}

int main() {
    // Create circular linked list: 2, 3, 4
    struct Node *first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);

    struct Node *last = first->next->next;
    last->next = first;

    printList(last);

    int found;
    int key = 4;
    found = search(last, key);
    if(found) {
        printf("Value %d found in the list.\n", key);
    }
    else {
        printf("Value %d not found in the list.\n", key);
    }

    key = 7;
    found = search(last, key);
    if(found) {
        printf("Value %d found in the list.\n", key);
    }
    else {
        printf("Value %d not found in the list.\n", key);
    }
}