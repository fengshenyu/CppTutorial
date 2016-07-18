#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
int main( ) {   
    int i;
    srand((unsigned)time(NULL));  
    for( i = 0; i < 10;i++ ) {
        printf("%d\n", rand() % 10);
    }
    return 0;
}