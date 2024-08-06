#include <stdio.h>

// Mengakses data pada Struct
struct Weapon {
    char *name;
    int attack;
    int guard;
};
struct Player {  //nested struct
    char *name;
    int score;
    int hp;
    struct Weapon *weapon;
};

int main() {
    // Dot Notation
    struct Player player1;
    player1.name    = "Petani Kode";
    player1.score   = 0;
    player1.hp      = 100;

    (*player1.weapon).name = "Katana";
    (*player1.weapon).attack = 16;
    (*player1.weapon).guard = 10;

    // Arrow Notation
    struct Player player;  // membuat struct player
    struct Player *player2;  // membuat pointer untuk player
    player2 = &player;

    player2->name    = "Petani Kode";
    player2->score   = 0;
    player2->hp      = 100;

    player2->weapon->name = "Katana";
    player2->weapon->attack = 16;
    player2->weapon->guard = 10;


    // cetak status player
    printf("PLAYER STATUS\n");
    printf("Name: %s\n", player2->name);
    printf("Score: %d\n", player2->score);
    printf("HP: %d\n", player2->hp);
    printf("Weapon\n");
    printf("  name: %s\n", player2->weapon->name);
    printf("  attack: %d\n", player2->weapon->attack);
    printf("  guard: %d\n", player2->weapon->guard);
}