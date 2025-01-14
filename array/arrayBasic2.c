#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//src: https://www.geeksforgeeks.org/introduction-to-arrays-data-structure-and-algorithm-tutorials/

//fixed sized array
int arr1[] = { 1, 2, 3, 4, 5 };  //This array will store integer type element
char arr2[10] = { 'a', 'b', 'c', 'd', 'e' };  //store char type element
float arr3[20] = { 1.4, 2.0, 24, 5.0, 0.0 };  ///store float type element

//dynamic allocated array
void dynamicArray() {
    // Kamus
    int n;
    int freq, jumlah;
    int *tabInt;

    // Algoritma
    printf("Masukan panjang tabel: ");
    scanf("%d", &n);  //ukuran Tabel
    tabInt = (int*)malloc(n*sizeof(int));

    printf("Masukan elemen tabel: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &tabInt[i]);  //mengisi elemen tabel
    }
}

/* Traversal in array */
int arr[] = { 1, 2, 3, 4, 5 };
int len = sizeof(arr) / sizeof(arr[0]);

for (int i = 0; i < len; i++) { // Traversing over arr[]
    printf("%d ", arr[i]);
}

/* Insertion in array */
void insertElement(int arr[], int n, int x, int pos) {  //insert at specific position
    // shift elements to the right
    // which are on the right side of pos
    for (int i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];

    arr[pos] = x;
}

/* Deletion in array */
int findElement(int arr[], int n, int key);  // To search a key to be deleted
int deleteElement(int arr[], int n, int key) {
    // Find position of element to be deleted
    int pos = findElement(arr, n, key);
 
    if (pos == -1) {
        printf("Element not found");
        return n;
    }
 
    // Deleting element
    int i;
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
 
    return n - 1;
}
int findElement(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
     // Return -1 if key is not found
    return -1;
}

/* Searching in array */
int findElement(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
 
    // If the key is not found
    return -1;
}
