#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// JIKA MAX_SIZE 1JT LOLOS 8 TESTCASE & WRONG_ANSWER 3 TESTCASE
// JIKA MAX_SIZE 10JT LOLOS SEMUA TESTCASE
#define MAX_SIZE 10000000

int arr[MAX_SIZE];
int front = 0, back = 0;
int output[MAX_SIZE];  // array untuk menyimpan output
int front_result = 0, back_result = 0;
int queue_size = 0;

void push_to_result(int item) {  // push back ke array output[]
    if(back_result < MAX_SIZE) {
        output[back_result] = item;
        back_result++;
    }
}
// biasa disebut "enqueue"
void add(int x, int y) {  // push_back bilangan x sebanyak y kali
    if (back < MAX_SIZE) {
        for(int i = 0; i < y; i++) {
            arr[back] = x;
            back++;
        }
    }

    queue_size += y;
    push_to_result(queue_size);
}
// biasa disebut "dequeue"
void del(int y) {  // pop_front sebanyak y kali
    push_to_result(arr[front]);

    front+= y;
    queue_size -= y;
}
void rev() {
    int left = front, right = back-1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        char perintah[100];
        scanf("%s", &perintah);
        if (strcmp(perintah, "add") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            add(x, y);
        } else if (strcmp(perintah, "del") == 0) {
            int y;
            scanf("%d", &y);
            del(y);
        } else if (strcmp(perintah, "rev") == 0) {
            rev();
        }
    }

    for(int i = front_result; i < back_result; i++) {
        printf("%d\n", output[i]);
    }
}