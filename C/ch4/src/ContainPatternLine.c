#include <stdio.h>

int main() {
    FILE *fp;
    char ch;
    if ((fp = fopen("content.txt","r")) == NULL) {
        printf("\nCannot open file strike any key exit!");
        getch();
        exit(1);
    }

    while((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }


    // printf(*result, "%c");
    if (fclose(fp) != 0) {
        printf("\nCannot close file.");
        getch();
        exit(1);
    }
    return 0;
}
