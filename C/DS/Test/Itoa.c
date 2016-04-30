#include <stdio.h>
#include <string.h>
void main(){
    char a[10];
    itoa(100, a, 10);
    char name[20] = "name";
    strcat(name, a);
    printf("%s\n", name);
}