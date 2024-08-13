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

struct Node *deleteFront(struct Node *last) {
    if(last == NULL) {
        printf("List is empty");
        return NULL;
    }

    struct Node *first = last->next;
    if(first == last) {  //if there is only 1 node in list
        free(first);
        last = NULL;
    } else {  //if the list is >1 node
        last->next = first->next;
        free(first);
    }
    
    return last;
}
struct Node *deleteEnd(struct Node *last) {
    if(last == NULL) {
        printf("List is empty");
        return NULL;
    }

    // curr will point to head initially
    struct Node *curr = last->next;
    if(curr == last) {  //if there is only 1 node in list
        free(curr);
        last = NULL;
    } else {  //if the list is >1 node
        while(curr->next->next != NULL) {  //push curr to second_last node
            curr = curr->next;
        }
        curr->next = last->next;
        last = curr;
    }
    return last;
}
struct Node *deleteAtPosition(struct Node *last, int position) {
    if(last == NULL) {
        printf("List is empty");
        return NULL;
    }

    if(last->next == last) {  //if only 1 node
        free(last);
        return NULL;
    }

    // curr will point to head initially
    struct Node *curr = last->next;

    // if position = 1
    if(position == 1) {
        last->next = curr->next;
        free(curr);
        return last;
    }

    // if position > 1
    for(int i = 1; i < position - 1; i++) {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    free(curr->next);
    return last;
}
struct Node *deleteSpecificNode(struct Node *last, int key) {
    if(last == NULL) {
        printf("List is empty");
        return NULL;
    }

    struct Node *curr = last->next;
    struct Node *prev = last;

    // if the node to be deleted is the only node in the list
    if(curr == last && curr->data == key) {
        free(curr);
        last = NULL;
        return last;
    }

    // If the node to be deleted is the first node
    if(curr->data == key) {
        last->next = curr->next;
        free(curr);
        return last;
    }

    // Traverse the list to find the node to be deleted
    while(curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is found
    if(curr->data == key) {
        prev->next = curr->next;
        if(curr == last) {
            last = prev;
        }
        free(curr);
    } else {  // If the node to be deleted is not found
        printf("Node with data %d not found.\n", key);
    }

    return last;
}