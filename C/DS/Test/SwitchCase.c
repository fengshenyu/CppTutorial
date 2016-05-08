#include <stdio.h>
#define true 1
#define false 0
typedef int bool;
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
int main() {
    printf("result=%d\n", isOperator('1'));
    return 0;
}