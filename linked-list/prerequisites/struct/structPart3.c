#include <stdio.h>

// Passing struct ke dlm fungsi
struct student {
    char *name;
    int age;
};

int main() {
    struct student s1;

    s1.name = "Edo";
    s1.age = 21;

    display(s1);   // passing structure as an argument

    return 0;
}

// membuat fungsi dengan struct sebagai parameter
void display(struct student s) {
  printf("\nDisplaying information\n");
  printf("Name: %s", s.name);
  printf("\nAge: %d", s.age);
}