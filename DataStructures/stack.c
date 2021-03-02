#include <stdio.h>

#define CAPACITY 500
int stackData[CAPACITY] = {0};
int stackPointer = 0;

int push(int data) {
    if (stackPointer >= CAPACITY) {
        printf("Stack is full.");
        return -1;
    } else {
        stackData[stackPointer] = data;
        stackPointer++;
    }
}

int pop() {
    if (stackPointer <= 0) {
        printf("Stack is empty.");
        return -1;
    } else {
        return stackData[--stackPointer];
    }
}

void clear() {
    stackPointer = 0;
}

int main() {

    push(10);
    push(20);
    push(30);

    printf("Items after push\n");
    for (int i=0; i<stackPointer; i++) {
        printf("Item %d: %d\n", i, stackData[i]);
    }
    printf("\n");

    pop();

    printf("Items after pop\n");
    for (int i=0; i<stackPointer; i++) {
        printf("Item %d: %d\n", i, stackData[i]);
    }
    printf("\n");

    clear();
    printf("Items after clear\n");
    for (int i=0; i<stackPointer; i++) {
        printf("Item %d: %d\n", i, stackData[i]);
    }
    printf("\n");

    return 0; 
}