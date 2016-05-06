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

bool isOperator(char letter) {
    switch(letter) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
        return true;
    defaule:
        return false;
    }
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
        ele->value = getValue(strMid, start + 1);
        ele->isOperator = false;
    }
}

void initMid(ExpressionEle mid[], char* strMid) {
    int i = 0;
    while (strMid[i] != '\0') {
        initEle(&(mid[i]), strMid, &i);
    }
}

void printMid(ExpressionEle mid[], int num) {
    for (int i = 0; i < num; i++) {
        if (mid[i].isOperator) {
            printf("%c", mid[i].operator);
        } else {
            printf("%d", mid[i].value);
        }
    }
    printf("\n");
}

void init(Stack* pStack) {
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

void porcessOperator() {

}


void initPost(ExpressionEle mid[], ExpressionEle post[], int len) {
    for (int i = 0; i < len; i++) {
        if (mid[i].isOperator) {

        } else {
            post[i] = mid[i];
        }
    }
}

void main() {
    char* strMid = "3*(1+23451)/5*2+(2-1)";
    int strNum = strlen(strMid);
    ExpressionEle mid[strNum];
    initMid(mid, strMid);
    // printMid(mid, strlen(strMid));

    ExpressionEle post[strNum];
}