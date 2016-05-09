#include <stdio.h>

typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;
typedef struct BinarySturct{
    Student data;
    struct BinarySturct* lChild;
    struct BinarySturct* rChild;
};

int main() {

    return 0;
}