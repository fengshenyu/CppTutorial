#include <stdio.h>
#include <stdlib.h>

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
        int srcIndex, int patternIndex) {
    int i = patternIndex;
    for (; pattern[i] != '\0' &&
        src[index + i] == pattern[i]; i++) {
            ;
    }
    return pattern[i] == '\0' ? -1 : i;
}
void search(char src[], char pattern[]) {
    int patternLen = strlen(pattern);
    int* kmpList = (int*) malloc(patternLen);
    loadListItem(&kmpList, pattern);
    printf("kmplist=");
    for (int i = 0; i < patternLen; i++) {
        printf("%d", *(kmpList + i));
    }
    printf("\n");

    int result = -1;
    for (int i = 0; src[i] != '\0';) {
        int unMatchPos = match(src, pattern, i);
        if (unMatchPos == -1) {
            result = i;
            break;
        }
        i = (unMatchPos == 0) ? i + 1 :
            (i + unMatchPos - *(kmpList + unMatchPos));
        printf("i=%d\n", i);
    }
    printf("first match pos is :%d", result);
}

void main() {
    char src[] =     "bbc abcdab abcdabcdabde";
    char pattern[] =                "abcdabd";
    search(src, pattern);
}
