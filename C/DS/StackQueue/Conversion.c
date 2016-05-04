#include <stdio.h>
#define TOTAL_SIZE 100
#define true 1
#define false 0
#define N 8
typedef int bool;


typedef struct StackStruct {
    int* base;
    int* top;
    int size;
}Stack;

void init(Stack* pStack) {
    pStack->base = (int*)malloc(sizeof(int) * TOTAL_SIZE);
    pStack->top = pStack->base;
    pStack->size = TOTAL_SIZE;
}

bool push(Stack* pStack, int data) {
    if (pStack->top - pStack->base == TOTAL_SIZE) {
        return false;
    }
    *(pStack->top) = data;
    pStack->top++;
    return true;
}

bool pop(Stack* pStack, int* data) {
    if (pStack->base == pStack->top) {
        return false;
    }
    pStack->top--;
    *data = *(pStack->top);
    return true;
}

bool empty(Stack stack) {
    return stack.base == stack.top;
}

void main() {
    Stack stack;
    init(&stack);
    printf("Input a integer:");
    int quotients;
    scanf("%d", &quotients);
    do {
        push(&stack, quotients % N);
        quotients = quotients / N;
    } while(quotients != 0);
    printf("result=");
    while (!empty(stack)) {
        int tmp;
        pop(&stack, &tmp);
        printf("%d", tmp);
    }

}