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
// Menampilkan data dalam linked list(dari depan)
struct Node *printFromFront(struct Node *head) {
    struct Node *current = head;

    if(current->prev != NULL) {  //jika current bukan first node, maka geser sampai first node
        while(current->prev != NULL) {
            current = current->prev;
        }
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
// Menampilkan data dalam linked list(dari belakang)
struct Node *printFromEnd(struct Node *head) {
    struct Node *current = head;

    if(current->next != NULL) {  //jika current bukan last node, maka geser sampai last node
        while(current->next != NULL) {
            current = current->next;
        }
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

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

    return head;
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

struct Node *deleteAtPosition(struct Node *head, int position) {
    // if list is empty
    if(head == NULL) return head;

    // if list >0 node
    struct Node *current = head;
    for(int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }
    if(current == NULL) return head;  //if position is out of range
    if(current->prev) current->prev->next = current->next;  //if current node have prev node
    if(current->next) current->next->prev = current->prev;  //if current node have next node
    if(head == current) head = head->next;  //if the node to be deleted is the head node

    free(current);
    return head;
}

int main() {
    // Membuat beberapa node
    struct Node *node1 = createNode(1);
    struct Node *node2 = createNode(2);
    struct Node *node3 = createNode(3);
    struct Node *node4 = createNode(4);
    struct Node *node5 = createNode(5);

    // Menghubungkan node-node tersebut
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    struct Node *head = node1;
    // Melakukan deletion
    printFromFront(head);  //<-1-><-2-><-3-><-4-><-5->
    head = deleteAtPosition(head, 3); 
    printFromFront(head);  //<-1-><-2-><-4-><-5->
    head = deleteFromEnd(head);
    printFromFront(head);  //<-1-><-2-><-4->
    head = deleteFromFront(head);
    printFromFront(head);  //<-2-><-4->
    printFromEnd(head);  //<-4-><-2->
    
}