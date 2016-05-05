#include <stdio.h>
#define SIZE 50000
void main(){
    FILE *fp;
    if((fp = fopen("string.data","w")) == NULL){
        printf("Cannot open file strike any key exit!");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++) {
        char result[40] = "";
        char numStr[10] = "";
        itoa(i, numStr, 10);
        strcat(result, numStr);
        strcat(result, ",");
        strcat(result, "name");
        strcat(result, numStr);
        strcat(result, "\n");
        fputs(result, fp);
    }
    printf("Write finished.\n");
    fclose(fp);
}