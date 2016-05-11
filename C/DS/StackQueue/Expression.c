#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1
#define false 0
#define TOTAL_SIZE 100

typedef int bool;
typedef struct {
    int value;
    char operator;
    bool isOperator;
}ExpressionEle;
typedef struct StackStruct {
    ExpressionEle* base;
    ExpressionEle* top;
    int size;
}Stack;
typedef struct {
    ExpressionEle *ele;
    int used;
    int total;
}Sequence;

bool isOperator(char letter) {
    bool result;
    switch(letter) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
        result = true;
        break;
    default:
        result = false;
        break;
    }
    return result;
}

bool currentLessEqualTop(char current, char top) {
    bool result;
    switch(current) {
    case '+':
    case '-':
        result = (top != '(');
        break;
    case '*':
    case '/':
        if (top == '+' || top == '-'  || top == '(') {
            result = false;
        } else {
            result = true;
        }
        break;
    default:
        result = false;
        break;
    }
    return result;
}

int getValue(char* strMid, int* start) {
    int end = *start;
    while (!isOperator(strMid[end]) && strMid[end] != '\0') {
        end++;
    }
    int len = end - *start + 1;
    char num[len + 1];
    strncpy(num, (strMid + *start - 1), len);
    num[len + 1] = '\0';
    *start = end;
    return atoi(num);
}

void initEle(ExpressionEle* ele, char* strMid, int* start) {
    if (isOperator(strMid[*start])) {
        ele->operator = strMid[*start];
        ele->isOperator = true;
        (*start)++;
    } else {
        (*start)++;
        ele->value = getValue(strMid, start);
        ele->isOperator = false;
    }
}

bool addLast(Sequence* pSequence, ExpressionEle ele) {
    if (pSequence->used == TOTAL_SIZE){
        return false;
    }
    *(pSequence->ele + pSequence->used) = ele;
    pSequence->used++;
    return true;
}

void initMid(Sequence* midSequence, char* strMid) {
    int i = 0;
    while (strMid[i] != '\0') {
        ExpressionEle ele;
        initEle(&ele, strMid, &i);
        addLast(midSequence, ele);
    }
}

void printExpression(Sequence* pSequence) {
    for (int i = 0; i < pSequence->used; i++) {
        if ((pSequence->ele + i)->isOperator) {
            printf("%c,", (pSequence->ele + i)->operator);
        } else {
            printf("%d,", (pSequence->ele + i)->value);
        }
    }
    printf("\n");
}

void initStack(Stack* pStack) {
    pStack->base = (ExpressionEle*)malloc(sizeof(ExpressionEle) * TOTAL_SIZE);
    pStack->top = pStack->base;
    pStack->size = TOTAL_SIZE;
}

bool push(Stack* pStack, ExpressionEle ele) {
    if (pStack->top - pStack->base == TOTAL_SIZE) {
        return false;
    }
    *(pStack->top) = ele;
    pStack->top++;
    return true;
}

bool pop(Stack* pStack, ExpressionEle* ele) {
    if (pStack->base == pStack->top) {
        return false;
    }
    pStack->top--;
    *ele = *(pStack->top);
    return true;
}

bool getTop(Stack* pStack, ExpressionEle* ele) {
    if (pStack->base == pStack->top) {
        return false;
    }
    ExpressionEle* top = pStack->top - 1;
    *ele = *top;
    return true;
}

bool isEmpty(Stack* pStack) {
    return pStack->base == pStack->top;
}

void processRightBracket (Sequence* mid, Sequence* post, 
        int midIndex, Stack* pStack) {
    ExpressionEle topEle;
    pop(pStack, &topEle);
    while (topEle.operator != '(') {
        addLast(post, topEle);
        pop(pStack, &topEle);
    }
}

void porcessOperator(Sequence* mid, Sequence* post, 
        int midIndex, Stack* pStack) {
    char current = (mid->ele + midIndex)->operator;
    if (current == ')') {
        processRightBracket(mid, post, midIndex, pStack);
        return;
    }
    ExpressionEle topEle;
    bool getSuccess = getTop(pStack, &topEle);
    if (!getSuccess) {//栈是空的直接进栈
        push(pStack, *(mid->ele + midIndex));
        return;
    }
    if (!currentLessEqualTop(current, topEle.operator)) {
        //当前符号大于栈顶元素直接进栈
        push(pStack, *(mid->ele + midIndex));
        return;
    }
    do { 
        pop(pStack, &topEle);
        addLast(post, topEle);
        getSuccess = getTop(pStack, &topEle);
    } while((getSuccess && currentLessEqualTop(current, topEle.operator)));
    push(pStack, *(mid->ele + midIndex));
}

void initPost(Sequence* mid, Sequence* post) {
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < mid->used; i++) {
        if ((mid->ele + i)->isOperator) {
            porcessOperator(mid, post, i, &stack);
        } else {
            addLast(post, *(mid->ele + i));
        }
    }
    while (!isEmpty(&stack)) {
        ExpressionEle topEle;
        pop(&stack, &topEle);
        addLast(post, topEle);
    }
}

void initSequence(Sequence* pSequence) {
    ExpressionEle* ele = (ExpressionEle*)malloc(
        sizeof(ExpressionEle) * TOTAL_SIZE);
    pSequence->ele = ele;
    pSequence->used = 0;
    pSequence->total = TOTAL_SIZE;
}

int getCalcValue(int a, int b, char operator) {
    int result;
    switch (operator) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }
    return result;
}

int calculate(Sequence* post) {
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < post->used; i++) {
        if ((post->ele + i)->isOperator) {
            ExpressionEle ele1;
            ExpressionEle ele2;
            pop(&stack, &ele1);
            pop(&stack, &ele2);
            ExpressionEle result;
            result.isOperator = false;
            result.value = getCalcValue(
                ele2.value, ele1.value, (post->ele + i)->operator);
            push(&stack, result);
        } else {
            push(&stack, *(post->ele + i));
        }
    }
    ExpressionEle finalResult;
    pop(&stack, &finalResult);
    return finalResult.value;
}

int main() {
    char* strMid = "9+(3-1)*3+10/2+1000*10";
    Sequence mid;
    initSequence(&mid);
    initMid(&mid, strMid);
    printExpression(&mid);

    Sequence post;
    initSequence(&post);
    initPost(&mid, &post);
    printExpression(&post);

    printf("Result=%d\n", calculate(&post));
    return 0;
}