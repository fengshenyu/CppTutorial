#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calListItem(char pattern[], int index) {
    int i = index;
    for (; i > 0; i--) {
        int j = 0, found = 0, dif = index - i + 1;;
        while (i > j) {
            if (pattern[j] != pattern[j + dif]) {
                found = 1;
                break;
            }
            j++;
        }
        if (found == 0) {
            break;
        }
    }
    return i;
}

void loadListItem(int** kmpList, char pattern[]) {
    int i = 0;
    for (; pattern[i] != '\0'; i++) {
        *(*kmpList + i) = calListItem(pattern, i);
    }
}

int match(char src[], char pattern[],
        int* srcIndex, int* patternIndex, int* kmpList) {
    for (; pattern[*patternIndex] != '\0' &&
        src[*srcIndex] == pattern[*patternIndex];
        (*srcIndex)++, (*patternIndex)++) {
          ;
    }
    if (pattern[*patternIndex] == '\0') {
        return -1;
    } else {
        if (*patternIndex == 0) {
            (*srcIndex)++;
        } else {
            *patternIndex =
                *(kmpList + *patternIndex - 1);
        }
        return 0;
    }
}

void search(char src[], char pattern[]) {
    unsigned patternLen = strlen(pattern);
    int* kmpList = (int*) malloc(patternLen * sizeof(int));
    loadListItem(&kmpList, pattern);
    printf("kmplist=");
    for (int i = 0; i < patternLen; i++) {
        printf("%d", *(kmpList + i));
    }
    printf("\n");

    int result = -1;
    for (int srcIndex = 0, patternIndex = 0; src[srcIndex] != '\0';) {
        int unMatchPos = match(src, pattern, &srcIndex, &patternIndex,
                kmpList);
        if (unMatchPos == -1) {
            result = srcIndex;
            break;
        }
    }
    printf("first match pos is :%d\n", result - patternLen);
    free(kmpList);
}

int main() {
    char src[] = "abcdabd";
    // char src[] = "bbc abcdab abcdabcdabde";
    char pattern[] = "abcdabd";
    search(src, pattern);
    return 0;
}

gcc -std=c99 -Wall KMPList.c
