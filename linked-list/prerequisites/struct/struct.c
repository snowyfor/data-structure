#include <stdio.h>

/* Structure: https://www.petanikode.com/c-struct/
Struct sama dengan Object di JavaScript.

Struct(tipe data bentukan) sama seperti Array yg menyimpan
banyak nilai ke dlm 1 variable, bedanya jika Array hanya bisa
menyimpan nilai2 yang tipe datanya sama, sedangkan Struct bisa
menyimpan nilai2 yang tipe datanya berbeda-beda.
*/

// Membuat Struct
struct Dosen {
    char *nama;
    char *prodi;
    int nip;
};

typedef struct {
    char *nama;
    char *kelas;
    int nim;
} Mahasiswa;

int main() {
    // Menggunakan struct(spt membuat object dlm constructor di JS)
    struct Dosen dos1;

    // mengisi nilai ke struct (cara 1 - dot notation)
    dos1.nama = "Jack Jr";
    dos1.prodi = "CompSci";
    dos1.nip = 1234;

    // mengisi nilai ke struct (cara 2 - cara langsung)
    struct Dosen dos2 = {
        .nama = "Carlos Donaldson",
        .prodi = "Psychology",
        .nip = 5678
    };

    // perbedaan dgn typedef & tanpa typedef (penejelasan cek README.md web petanikode)
    Mahasiswa mhs1 = {
        .nama = "Jimmy",
        .kelas = "A",
        .nim = 1001
    };

    // mencetak isi struct
    printf("## Dosen 1 ##\n");
    printf("Nama: %s\n", dos1.nama);
    printf("Alamat: %s\n", dos1.prodi);
    printf("Umur: %d\n", dos1.nip);

    printf("## Dosen 2 ##\n");
    printf("Nama: %s\n", dos2.nama);
    printf("Alamat: %s\n", dos2.prodi);
    printf("Umur: %d\n", dos2.nip);

    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.nama);
    printf("Alamat: %s\n", mhs1.kelas);
    printf("Umur: %d\n", mhs1.nim);

    return 0;
}
