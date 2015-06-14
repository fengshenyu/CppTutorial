#include <stdio.h>

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

// char* getList(char pattern[]) {
//     for (int i = 0; pattern[i] != '\0'; i++) {
//
//     }
// }

void main() {
    char pattern[] = "abcbab";
    printf("result=%d", calListItem(pattern, 5));
}
