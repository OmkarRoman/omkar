#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct {
int arr [MAX];
int top;
} Stack;

void initialize(Stack* s);
int isFull(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int accessElement(Stack* s, int index);
void display(Stack* s);
void initialize(Stack* s) {
s->top = -1;
}
int isFull(Stack* s) {
return s->top == MAX-1;
}
int isEmpty(Stack* s) {
return s->top == -1;
}
void push(Stack* s, int value) {
if (isFull(s)) {
printf("Stack Overflow\n");
return;
}
s->arr[++(s->top)] = value;
}
int pop(Stack* s) {
if (isEmpty(s)) {
printf("Stack Underflow\n");
return -1;
}
return s->arr[(s->top)--];
}
int peek(Stack* s) {
if (isEmpty(s)) {
printf("Stack is empty\n");
return -1;
}
return s->arr[s->top];
}
int accessElement(Stack* s, int index) {
if (index < 0 || index > s->top) {
return -1;
}
return s->arr[index];
}
void display(Stack* s) {
if (isEmpty(s)) {
printf("Stack is empty\n");
return;
}
int i;
 for(i=s->top; i>=0; i--) {
printf("%d\n",s->arr[i]);
}
}
int main() {
Stack s;
initialize(&s);
int choice, value, index;

do{
printf("\nStack Operation Menu:\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Peek\n");
printf("4. Access Element by Index\n");
printf("5. Display Stack\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice) {
case1:
printf("Enter value to push: ");
scanf("%d", &value);
push(&s, value);
break;
case2:
value = pop(&s);
if (value != -1) {
printf("Popped value: %d\n", value);
}
break;
case3:
value = peek(&s);
if (value != -1) {
printf("Top value: %d\n", value);
}
break;
case4:
printf("Enter index to access:");
scanf("%d", &index);
value = accessElement(&s, index);
if (value != -1) {
printf("Element at index %d:%d\n", index, value);
}
else {
printf("Index %d is out of bounds\n", index);
}
break;
case5:
printf("Stack elements:\n");
display(&s);
break;
case6:
printf("Exiting...\n");
break;
default:
printf("Invalid choice, please try again\n");
}
} while (choice != 6);
return 0;
}
