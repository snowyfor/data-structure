#include <stdio.h>

// nested struct
struct Weapon {
    char* name;
    int attackPower;
    int range;
};
struct Player {
    char* name;
    int healthPoin;
    struct Weapon weapon;
};

int main() {
    // menggunakan nested struct(cara 1)
    struct Player player1;

    player1.name = "Petani Kode";
    player1.healthPoin = 100;
    player1.weapon.name = "Katana";
    player1.weapon.attackPower = 30;
    player1.weapon.range = 100;

    // menggunakan nested struct(cara 2)
    struct Player player2 = {
        .name = "Petani Kode2",
        .healthPoin = 100, // 100%
        .weapon = {
            .name = "Katana",
            .attackPower = 30,
            .range = 100, // 1 meter
        }
    };

    // print player dan weapon
    printf("== Player Status ==\n");
    printf("Player: %s\n", player1.name);
    printf("HP: %d%\n", player1.healthPoin);
    printf("-- Weapon --\n");
    printf("   Name: %s\n", player1.weapon.name);
    printf("   Attack: %d\n", player1.weapon.attackPower);
    printf("   Range: %d\n", player1.weapon.range);
}
