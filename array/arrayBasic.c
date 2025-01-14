#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//src: https://www.petanikode.com/c-array/

//Cara membuat array hampir sama
//seperti cara membuat variabel biasa.
//Bedanya… pada array kita harus menentukan panjangnya.

int array[10];  //membuat array kosong dengan panjang 10
int arr[3] = {0, 3, 2}  // membuat array dg langsung diisi

char huruf[5] = {'a', 'b', 'c', 'd', 'e'};
huruf[2]; //'c'
huruf[2] = 'z';  //ganti isi arr huruf

// mengambil panjang array
int nilai[5] = {33, 22, 11, 44, 21};
int length = sizeof(nilai) / sizeof(*nilai);
printf("panjang array nilai: %d\n", length);

//latihan cari nilai rata-rata
void main() {
    int tinggiBadan[10] = {175, 165, 166, 157, 184, 156, 163, 176, 171, 169};

    int length = sizeof(tinggiBadan) / sizeof(*tinggiBadan);
    int sum = 0;

    for(int i = 0; i < length; i++) {
        sum += tinggiBadan[i];
    }

    float mean = (float)sum / (float)length;
    printf("rata-ratanya adalah: %.2f\n", mean);
}