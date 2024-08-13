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
    //if list is empty
    if (last == NULL) return;

    // start from the head node
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

    // Create a new node
    struct Node* newNode = createNode(data);

    // Update last to point to the new node
    last = newNode;
    return last;
}
struct Node *insertFront(struct Node *last, int data) {
    struct Node *newNode = createNode(data);
    //if the list is empty
    if(last == NULL) {
        newNode->next = newNode;
        return newNode;
    };

    newNode->next = last->next;
    last->next = newNode;
    return last;
}
struct Node *insertEnd(struct Node *last, int data) {
    struct Node *newNode = createNode(data);
    if(last == NULL) {
        last = newNode;
        newNode->next = newNode;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode; //because newNode become last
    return last; 
}
struct Node *insertAtPosition(struct Node *last, int data, int position) {
    struct Node *newNode = createNode(data);

    //if the list is empty
    if(last == NULL) {
        if(position != 1) {
            printf("invalid position due to empty list");
            return last;
        }

        //if position is 1
        last = newNode;
        last->next = last;  //make it point to itself
        return last;
    }

    // curr will point to head initially
    struct Node *curr = last->next;

    //if position is 1 (the first)
    if(position == 1) {
        newNode->next = curr;
        last->next = newNode;
        return last;
    }

    for(int i = 1; i < position - 1; i++) {  //traverse with i < position - 1 because this is singly not doubly(which can use i < position because we can use prev in doubly)
        curr = curr->next;

        // If position is out of bounds
        if (curr == last->next) {  //curr == last->next bisa mewakili position is out of bounds(di luar batas) karena (curr == last->next) artinya kembali ke titik awal, kembali ke titik awal aritnya sudah melebihi last, berapa kali pun curr ini mengitari list nya.
            printf("Invalid position!\n");
            return last;
        }
    }
    newNode->next = curr->next;
    curr->next = newNode;

    //if position is the last
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