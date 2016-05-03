#include <stdio.h>
#include <string.h>
typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;

void main(){
    char* str = "1999,nameqwerq";
    char* result = NULL;
    char* delims = ",";
    result = strtok(str, delims);
    printf( "result is \"%s\"\n", result );
    result = strtok(NULL, delims );
    printf( "result is \"%s\"\n", result );

}