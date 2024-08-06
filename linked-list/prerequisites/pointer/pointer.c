#include <stdio.h>

/*
Setiap variabel yang kita buat pada program akan memiliki alamat memori.
Alamat memori berfungsi untuk menentukan lokasi penyimpanan data pada memori (RAM).
Kadang alamat memori ini disebut reference atau referensi.

Pointer adalah sebuah variabel khusus yang berisi alamat memori.
“Pointer berisi alamat memori”
*/

int *pointer1 = 00001;  // *pointer1 mengakses data yg ada pd alamat memori 00001

/* Mengakses data dengan pointer (cek gambar di web utk memudahkan pemahaman) */
void main() {
    int score = 50;
    int hp = 100;

    // membuat pointer dengan isi alamat memori dari hp
    int *ptr_hp = &hp;

    // print isi variabel dan alama memori
    printf("ptr_hp \t %x \t %x \n", &ptr_hp, ptr_hp);
    printf("*ptr_hp \t %x \t %d \n", &ptr_hp, *ptr_hp);
    // & MENGAKSES ALAMAT DARI VAR ITU SENDIRI
    // TANPA TANDA : MENGAKSES ISI DARI ALAMAT VAR ITU SENDIRI
    // * MENGAKSES ISI DARI ALAMAT YANG DITUNJUK VAR ITU

    // mengubah data pada alamat memori dengan pointer(cek web)
    *ptr_hp = 95;

    printf("hp \t\t %x \t %d \n", &hp, hp);
    printf("*ptr_hp \t %x \t %d \n", &ptr_hp, *ptr_hp);
}