#include <stdio.h>

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
    struct Dosen dos1;

    dos1.nama = "Jack Jr";
    dos1.prodi = "CompSci";
    dos1.nip = 1234;

    struct Dosen dos2 = {
        .nama = "Carlos Donaldson",
        .prodi = "Psychology",
        .nip = 5678
    };

    Mahasiswa mhs1 = {
        .nama = "Jimmy",
        .kelas = "A",
        .nim = 1001
    };
}