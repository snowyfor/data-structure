#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Fungsi untuk membuat node baru
struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
};

int main() {
    // Membuat beberapa node
    struct Node *node1 = createNode(1);
    struct Node *node2 = createNode(2);
    struct Node *node3 = createNode(3);

    // Menghubungkan node-node tersebut
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;

    // Menampilkan data dalam linked list(dari depan)
    struct Node *current = node1;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    // Menampilkan data dalam linked list(dari belakang)
    struct Node *curr = node3;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->prev;
    }

    // Mengeluarkan memori yang digunakan oleh node
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
