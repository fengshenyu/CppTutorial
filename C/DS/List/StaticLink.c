#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

#define TOTAL_SIZE 10
typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;
typedef struct {
    Student data;
    int cur;
}Node, StaticLink[TOTAL_SIZE];

void init(StaticLink staticLink) {
    for (int i = 0; i < TOTAL_SIZE - 1; i++) {
        staticLink[i].cur = i + 1;
    }
    staticLink[TOTAL_SIZE - 1].cur = 0;
}
void printData(Student data) {
    printf("num=%d,name=%s\n", data.stuNum, data.stuName);
}

bool staticMalloc(StaticLink staticLink) {
    int spaceId = staticLink[0].cur;
    if (spaceId != TOTAL_SIZE - 1) {
        staticLink[0].cur = staticLink[spaceId].cur;
    } else {
        printf("malloc error.\n");
    }
    return spaceId;
}

void staticFree(StaticLink staticLink, int index) {
    staticLink[index].cur = staticLink[0].cur;
    staticLink[0].cur = index;
}

bool add(StaticLink staticLink, Student data, int index) {
    int spaceId = staticMalloc(staticLink);
    if (index < 0 || spaceId == TOTAL_SIZE - 1) {
        return false;
    }
    int tmp = TOTAL_SIZE - 1;
    int i = 0;
    while (i < index && staticLink[tmp].cur != 0) {
        tmp = staticLink[tmp].cur;
        i++;
    }
    if (i != index) {
        return false;
    }
    staticLink[spaceId].data = data;
    staticLink[spaceId].cur = staticLink[tmp].cur;
    staticLink[tmp].cur = spaceId;
    return true;
}

bool delete(StaticLink staticLink, Student* data, int index) {
    if (index < 0) {
        return false;
    }
    int tmp = TOTAL_SIZE - 1;
    int i = 0;
    while (i < index && staticLink[tmp].cur != 0) {
        tmp = staticLink[tmp].cur;
        i++;
    }
    if (i != index) {
        return false;
    }
    int pre = staticLink[tmp].cur;
    if (pre == 0) {
        return false;
    }
    *data = staticLink[pre].data;
    staticLink[tmp].cur = staticLink[pre].cur;
    staticFree(staticLink, pre);
    return true;
}

void print(StaticLink staticLink) {
    int i = TOTAL_SIZE - 1;
    // printf("Start print\n");
    while (staticLink[i].cur != 0) {
        printData(staticLink[staticLink[i].cur].data);
        i = staticLink[i].cur;
    }
}
void main() {
    StaticLink staticLink;
    init(staticLink);

    printf("Start add\n");
    Student stu1;
    stu1.stuNum = 1;
    stu1.stuName = "name1";
    add(staticLink, stu1, 0);
    Student stu2;
    stu2.stuNum = 2;
    stu2.stuName = "name2";
    add(staticLink, stu2, 0);
    Student stu3;
    stu3.stuNum = 3;
    stu3.stuName = "name3";
    add(staticLink, stu3, 1);
    Student stu4;
    stu4.stuNum = 4;
    stu4.stuName = "name4";
    add(staticLink, stu4, 2);
    Student stu5;
    stu5.stuNum = 5;
    stu5.stuName = "name5";
    add(staticLink, stu5, 4);
    Student stu6;
    stu6.stuNum = 6;
    stu6.stuName = "name6";
    add(staticLink, stu6, 1);
    print(staticLink);
    printf("\n");

    printf("Start delete\n");
    Student stu7;
    delete(staticLink, &stu7, 0);
    printf("Delete data:");
    printData(stu7);
    printf("After delete:\n");
    print(staticLink);
    Student stu8;
    delete(staticLink, &stu8, 2);
    printf("Delete data:");
    printData(stu8);
    printf("After delete:\n");
    print(staticLink);
    printf("\n");

    printf("add again\n");
    Student stu9;
    stu9.stuNum = 9;
    stu9.stuName = "name9";
    add(staticLink, stu9, 0);
    print(staticLink);
    printf("add\n");
    Student stu10;
    stu10.stuNum = 10;
    stu10.stuName = "name10";
    add(staticLink, stu10, 5);
    print(staticLink);
    printf("add\n");
    Student stu11;
    stu11.stuNum = 11;
    stu11.stuName = "name11";
    add(staticLink, stu11, 2);
    print(staticLink);
    printf("add\n");
    Student stu12;
    stu12.stuNum = 12;
    stu12.stuName = "name12";
    add(staticLink, stu12, 7);
    print(staticLink);
    printf("add\n");
    Student stu13;
    stu13.stuNum = 13;
    stu13.stuName = "name13";
    add(staticLink, stu13, 8);
    print(staticLink);
    printf("\n");

    printf("delete again\n");
    Student stu14;
    delete(staticLink, &stu14, 3);
    printf("Delete data:");
    printData(stu14);
    printf("After delete:\n");
    print(staticLink);
    printf("\n");

    printf("add again\n");
    Student stu15;
    stu15.stuNum = 15;
    stu15.stuName = "name15";
    add(staticLink, stu15, 7);
    print(staticLink);
}