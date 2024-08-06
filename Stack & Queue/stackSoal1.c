#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000000  // Ukuran maksimum array arr

int arr[MAX_SIZE];  // Array untuk menyimpan elemen
int front = 0, back = 0;  // Indeks untuk melacak posisi depan dan belakang antrian

// Fungsi untuk menambahkan elemen ke bagian belakang antrian
void push_back(int value) {
    if (back < MAX_SIZE) {
        arr[back++] = value;
    }
}

// Fungsi untuk menambahkan elemen ke bagian depan antrian
void push_front(int value) {
    if (back < MAX_SIZE) {
        if (front == 0) {
            // Jika front berada di awal array, geser semua elemen ke kanan
            for (int i = back; i > 0; --i)
                arr[i] = arr[i - 1];
            back++;
        } else {
            // Jika tidak, kurangi front untuk menambahkan elemen di depan
            front--;
        }
        arr[front] = value;
    }
}

// Fungsi untuk menghapus elemen dari bagian depan antrian
void pop_front() {
    if (front < back) {
        front++;
    }
}

// Fungsi untuk menghapus elemen dari bagian belakang antrian
void pop_back() {
    if (back > front) {
        back--;
    }
}


// DALAM C, UNTUK MEMBANDINGKAN ISI DARI 2 STRING KITA MENGGUNAKAN strcmp.
// The strcmp() compares two strings character by character. If the strings are equal, the function returns 0.
int main() {
    int n;  // Variabel untuk menyimpan jumlah perintah
    scanf("%d", &n);  // Membaca jumlah perintah
    while (n--) {  // n-- ADALAH BENTUK SINGKAT DARI MENULIS LOOP YANG AKAN DIEKSEKUSI SEBANYAK 'n' KALI
        char cmd[20];  // Array untuk menyimpan perintah
        int tmp;  // Variabel sementara untuk menyimpan nilai elemen
        scanf("%s", cmd);  // Membaca perintah
        if (strcmp(cmd, "push_back") == 0) {
            // Jika perintah adalah "push_back", baca nilai elemen dan tambahkan ke belakang
            scanf("%d", &tmp);
            push_back(tmp);
        } else if (strcmp(cmd, "push_front") == 0) {
            // Jika perintah adalah "push_front", baca nilai elemen dan tambahkan ke depan
            scanf("%d", &tmp);
            push_front(tmp);
        } else if (strcmp(cmd, "pop_front") == 0) {
            // Jika perintah adalah "pop_front", hapus elemen dari depan
            pop_front();
        } else if (strcmp(cmd, "pop_back") == 0) {
            // Jika perintah adalah "pop_back", hapus elemen dari belakang
            pop_back();
        }
    }
    // Cetak elemen-elemen yang tersisa dalam antrian dari depan ke belakang
    for (int i = front; i < back; i++)
        printf("%d\n", arr[i]);
    return 0;
}
