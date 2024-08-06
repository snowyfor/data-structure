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
struct Node *deleteFromFront(struct Node *head) {
    // if the list is empty
    if(head == NULL) return NULL;

    // if the list just 1 node
    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    // if >1 node
    struct Node *first = head;  //tandai first node
    head = head->next;  //geser head
    head->prev = NULL;
    free(first);  //hapus first node
    return head;
}
struct Node *deleteFromEnd(struct Node *head) {
    // if the list is empty
    if(head == NULL) return NULL;

    // if the list just 1 node
    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    // if >1 node
    struct Node *second_last = head;
    while(second_last->next->next != NULL) {  //cari second_last node
        second_last = second_last->next;
    }
    free(second_last->next);  //hapus last node
    second_last->next = NULL;  //buat next dari second_last jadi NULL shg second_last berubah menjadi last node(krn ciri dari last node adlah next node nya NULL)
    return head;
}
struct Node *deleteFromEnd2(struct Node *head) {  //(cara 2)
    if(head == NULL) return NULL;

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    // if >1 node
    struct Node *last = head;
    while(last->next != NULL) {  //cari last node
        last = last->next;
    }
    last->prev->next = NULL;  //buat last node jadi NULL
    free(last);

    return head
}
struct Node *deleteFromFront2(struct Node *head) {  //(cara 2)
    if(head == NULL) return NULL;

    // if >0 node
    struct Node *first = head;  //tandai first node
    head = head->next;  //geser head
    if(head != NULL) head->prev = NULL;  //jika head bukan 1 node(terlihat dari head setelah digeser != NULL)
    free(first);  //hapus first node
    return head;
}

struct Node *deleteAtPosition(struct Node *head) {
    
}