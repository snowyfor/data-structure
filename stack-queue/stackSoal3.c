#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];
int back = 0;
int stack_size = 0;

int output[MAX_SIZE];
int front_output = 0, back_output = 0;
void push_to_output(int item) {
    if (back_output < MAX_SIZE) {
        output[back_output] = item;
        back_output++;
    }
}

void add(int x, int y) {  //push_back bilangan x sebanyak y kali 
    if (back < MAX_SIZE) {
        for(int i = 0; i < y; i++) {
            arr[back] = x;
            back++;
        }
        stack_size += y;
        push_to_output(stack_size);
    }
}
void del(int y) {  //pop_back sebanyak y kali
    push_to_output(arr[back-1]);

    back -= y;
    stack_size -= y;
}
void adx(int x) {  //menambahkan x pada setiap elemen
    for(int i = 0; i < stack_size; i++) {
        arr[i] += x;
    }
}
void dex(int x) {  //mengurangi x pada setiap elemen
    for(int i = 0; i < stack_size; i++) {
        arr[i] -= x;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        char perintah[100];
        scanf("%s", &perintah);
        if(strcmp(perintah, "add") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            add(x, y);
        } else if(strcmp(perintah, "del") == 0) {
            int y;
            scanf("%d", &y);
            del(y);
        } else if(strcmp(perintah, "adx") == 0) {
            int x;
            scanf("%d", &x);
            adx(x);
        } else if(strcmp(perintah, "dex") == 0) {
            int x;
            scanf("%d", &x);
            dex(x);
        }
    }

    for(int i = front_output; i < back_output; i++) {
        printf("%d\n", output[i]);
    }
}