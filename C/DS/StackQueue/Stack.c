#include <stdio.h>
#define TOTAL_SIZE 100
#define true 1
#define false 0
typedef int bool;
typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;

typedef struct StackStruct {
    Student* base;
    Student* top;
    int size;
}Stack;

void init(Stack* pStack) {
    pStack->base = (Student*)malloc(sizeof(Student) * TOTAL_SIZE);
    pStack->top = pStack->base;
    pStack->size = TOTAL_SIZE;
}

void printData(Student data) {
    printf("num=%d,name=%s\n", data.stuNum, data.stuName);
}

void print(Stack* pStack) {
    if (pStack->top == pStack->base) {
        return;
    }
    Student* p = pStack->top - 1;
    while (pStack->base <= p) {
        printData(*p);
        p--;
    }
}


bool push(Stack* pStack, Student stu) {
    if (pStack->top - pStack->base == TOTAL_SIZE) {
        return false;
    }
    pStack->top->stuNum = stu.stuNum;
    pStack->top->stuName = stu.stuName;
    pStack->top++;
    return true;
}

bool pop(Stack* pStack, Student* stu) {
    if (pStack->base == pStack->top) {
        return false;
    }
    pStack->top--;
    *stu = *(pStack->top);
    return true;
}
void main() {
    Stack stack;
    init(&stack);

    printf("start push\n");
    Student stu1;
    stu1.stuNum = 1;
    stu1.stuName = "name1";
    push(&stack, stu1);
    Student stu2;
    stu2.stuNum = 2;
    stu2.stuName = "name2";
    push(&stack, stu2);
    Student stu3;
    stu3.stuNum = 3;
    stu3.stuName = "name3";
    push(&stack, stu3);
    Student stu4;
    stu4.stuNum = 4;
    stu4.stuName = "name4";
    push(&stack, stu4);
    print(&stack);
    printf("\n");

    printf("Start pop\n");
    Student stu5;
    pop(&stack, &stu5);
    printf("Pop:");
    printData(stu5);
    print(&stack);
}