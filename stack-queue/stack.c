#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// size of the stack
int size = 8;       
// stack storage
int stack[8];     
// top of the stack
int topOfStack = 0;            

//Operation : isFull
//return true if stack is full 
bool isFull(){
   return (topOfStack == size-1);
}
// Operation : Push
// push item on the top of the stack 
void push(int item) {
   if(!isFull()){
      // increment top by 1 and insert item
      stack[++topOfStack] = item;
   } else {
      printf("Cannot add item. Stack is full.\n");
   }      
}
// Operation : Pop
// pop item from the top of the stack 
int pop() {
   //retrieve data and decrement the top by 1
   return stack[topOfStack--];        
}
// Operation : top
// view the data at top of the stack 
int top() {       
   //retrieve data from the top
   return stack[topOfStack];
}
// Operation : isEmpty
// return true if stack is empty 
bool isEmpty(){
   return (topOfStack == 0);
}

main() {
   // push items on to the stack 
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("Element at top of the stack: %d\n" ,top());
   printf("Elements: \n");

   // print stack data 
   while(!isEmpty()){
      int data = pop();
      printf("%d\n",data);
   }
   printf("Stack full: %s\n" , isFull()?"true":"false");
   printf("Stack empty: %s\n" , isEmpty()?"true":"false");
}