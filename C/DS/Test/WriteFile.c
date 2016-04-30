#include <stdio.h>
#define SIZE 5000
void main(){
    FILE *fp;
    if((fp = fopen("string.data","w")) == NULL){
        printf("Cannot open file strike any key exit!");
        exit(1);
    }
    fputs("abc\n", fp);
    fputs("dec\n", fp);
    fclose(fp);
}