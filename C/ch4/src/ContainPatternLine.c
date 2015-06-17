#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
int END = 1;

char line[MAX + 1];

int match(char src[], char pattern[], int start) {
    int i, j;
    for (i = start, j = 0; src[i] != '\0' && pattern[j] != '\0' &&
        src[i] == pattern[j]; i++, j++) {
            ;
    }
    return pattern[j] == '\0' ? start : -1;
}


int strIndex(char src[], char pattern[]) {
    for (int i = 0; src[i] != '\0'; i++) {
        if (match(src, pattern, i) != -1) {
            return i;
        }
    }
    return -1;
}

void fillLine(FILE *fp) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF && i < MAX) {
        line[i++] = ch;
    }
    if (ch == EOF) {
        END = 0;
    }
    line[i] = '\0';
}

int main() {
    char pattern[] = "ab*";
    FILE *fp;
    if ((fp = fopen("content.txt","r")) == NULL) {
        printf("\nCannot open file strike any key exit!");
        getchar();
        exit(1);
    }
    while(END == 1) {
        fillLine(fp);
        if (strIndex(line, pattern) != -1) {
            printf("line=%s\n", line);
        }
    }

    if (fclose(fp) != 0) {
        printf("\nCannot close file.");
        getchar();
        exit(1);
    }
    return 0;
}

// gcc -Wall -std=c99 KMPList.c
