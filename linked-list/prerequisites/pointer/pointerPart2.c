#include <stdio.h>

// Pass by reference pada fungsi (penjelasan cek Web)
void tambah_skor(int skor) {
    skor = skor + 5;
    printf("score diubah ke: %d\n", skor);
}
void add_score(int *score) {
    *score = *score + 5;
    printf("score diubah ke: %d\n", *score);
}

void main() {
    int score = 0;

    printf("score sebelum diubah: %d\n", score);
    tambah_skor(score);  // pass by value
    printf("score setelah diubah(pass by value): %d\n", score);
    add_score(&score);  // pass by reference
    printf("score setelah diubah(pass by reference): %d\n", score);
}