#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
typedef int bool;

typedef struct {
    int value;
    char operator;
    bool isOperator;
}ExpressionEle;

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

int getValue(char* strMid, int* start) {
    int end = *start;
    while (!isOperator(strMid[end]) && strMid[end] != '\0') {
        end++;
    }
    int len = end - start + 1;
    char num[len + 1];
    strncpy(num, (strMid + start - 1), len);
    num[len + 1] = '\0';
    *start = end;
    return atoi(num);
}

void initEle(ExpressionEle* ele, char* strMid, int* start) {
    if (isOperator(strMid[*start])) {
        ele->operator = strMid[*start];
        ele->isOperator = true;
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

void main() {
    ExpressionEle mid[100];
    char* strMid = "9+(3-1)*3+10/2";
}