#include <stdio.h>
#include <string.h>
void main() {
    char s[] = "1,name1";
    char *delim = "-";
    char *p;
    printf("%s", strtok(s, delim));
    while (p = strtok(NULL, delim))
        printf("%s ", p);
    printf("\n");
}