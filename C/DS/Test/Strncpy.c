#include <stdio.h>
#include <string.h>
#include <malloc.h>
void main(){
    char* a = "abcdefgh";
    char* b = (char*)malloc(sizeof(char) * 3);
    strncpy(b, (a + 2), 2);
    *(b + 2) = '\0';
    printf("b=%s\n", b);
}