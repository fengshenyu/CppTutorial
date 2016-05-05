#include <stdio.h>
#define ADD -1
#define SUB -2
#define MUL -3
#define DIV -4
#define LEFT -5
#define RIGHT -6

int getOperator(char operator) {
    int result;
    switch(operator) {
    case '+':
        result = ADD;
        break;
    case '-':
        result = SUB;
        break;
    case '*':
        result = MUL;
        break;
    case '/':
        result = DIV;
        break;
    case '(':
        result = LEFT;
        break;
    case ')':
        result = RIGHT;
        break;
    }
    return result;
}

void init(int intMid[], char* strMid) {
    for (int i = 0; *(strMid + i) != '\0'; i++) {
        char cur = *(strMid + i);
        if ( cur>= '0' || cur <= '9') {

        } else {
            intMid[i] = getOperator();
        }
    }
}

void main() {
    int intMid[100];
    char* strMid = "9+(3-1)*3+10/2";
}