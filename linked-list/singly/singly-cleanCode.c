#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node
struct Node {
    int data;
    struct Node *next;
};

// Fungsi untuk membuat node baru
struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
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
    node2->next = node3;

    // Menampilkan data dalam linked list
    struct Node *current = node1;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Mengeluarkan memori yang digunakan oleh node
    free(node1);
    free(node2);
    free(node3);

    return 0;
}