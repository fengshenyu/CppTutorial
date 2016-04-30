#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

#define TOTAL_SIZE 5000
typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;
typedef struct {
    Student data;
    int next;
}Node, StaticLink[TOTAL_SIZE];

void init(StaticLink staticLink) {
    staticLink[0].next = 0;
}
void printData(Student data) {
    pritf("num=%d,name=%s", data.stuNum, data.stuName);
}

bool addHead() {
    
}
bool add(StaticLink staticLink, int index, Student stu) {
    if (index < 0) {
        return false;
    }
    return true;
}
void main() {
    StaticLink staticLink;
    init(staticLink);
    printf("%d\n", staticLink[0].next);
}