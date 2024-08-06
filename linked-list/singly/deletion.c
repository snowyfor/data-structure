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
void printList(struct Node *head) {
    struct Node *current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node *deleteFront(struct Node *head) {
    if (head == NULL) return NULL;

    struct Node *temp = head;
    
    head = head->next;
    free(temp);
    return head;
}
struct Node *deleteEnd(struct Node *head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    struct Node *second_last = head;
    while(second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
    return head;
}
struct Node *deleteMiddle(struct Node *head, int position) {
    struct Node *prev = head;
    struct Node *temp = head;

    if (head == NULL) return NULL;

    if(position == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    for(int i = 1; i < position && head != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp != NULL) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Data not present\n");
    }
    return head;
}

int main() {
    // Create the linked list 1->2->3->4->5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head = deleteFront(head);  //2->3->4->5
    head = deleteEnd(head);  //2->3->4
    head = deleteMiddle(head, 2);  //2->4
    printList(head);

}