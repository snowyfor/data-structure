// Alokasi Memori malloc() calloc() realloc() free()
/*
utk membuat variable yg ukurannya dinamis(mengikuti ukuran input),
kita perlu alokasi memori ke Heap agar tidak Stack overflow
*/
#include <stdio.h>
#include <stdlib.h>  // WAJIB

// malloc() : mengalokasikan memori ke Heap
int *score = malloc(32);  // membuat var score & disimpan ke dalam heap dg ukuran 32byte
int *skor = malloc(sizeof(int));  // membuat var skor & disimpan ke dalam heap mengikuti ukuran tipe data int (4byte)

char name[] = "Petani Kode"; // diinputkan user
// membuat var name & disimpan ke dlm heap DG UKURAN SESUAI INPUT USER
char *name = malloc(sizeof(name));

int main(){
    struct Player {
        char *name;
        unsigned int hp;
        unsigned int xp;
        unsigned int level;
    };

    // menggunakan malloc
    struct Player *player1 = malloc(sizeof(struct Player));

    player1->name = "Petani Kode";
    player1->hp = 100;
    player1->xp = 5;
    player1->level = 1;

    printf(":: PLAYER STATUS ::\n");
    printf("name : %s\n", player1->name);
    printf("hp   : %d\n", player1->hp);
    printf("xp   : %d\n", player1->xp);
    printf("level: %d\n", player1->level);
}