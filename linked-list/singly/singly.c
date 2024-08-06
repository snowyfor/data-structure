#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node
struct Node {
    int data;
    struct Node *next;  //utk memahaminya cek pointerPart4.c bagian nested struct
    //struct Node* next; (sama artinya dg yg atas)
};

// Fungsi untuk membuat node baru
struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));  // utk memahaminya cek malloc.c bagian menggunakan malloc
    // knp *newNode pake pointer? krn kita akan membuat var dg ukuran dinamis
    // knp *newNode harus dinamis? krn node dalam linked list itu dinamis(bisa bertambah dan bisa berkurang)
    // dan juga agar newNode bisa diakses di luar fungsi
    //struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); [sama artinya dg yg atas]
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Membuat beberapa node
    struct Node *node1 = createNode(1);  //*node1 perlu jadi pointer krn node yang Anda buat berada di heap, bukan di stack.
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