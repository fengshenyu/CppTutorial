#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;

typedef struct DoubleLinkStruct{
    struct DoubleLinkStruct* pre;
    Student* data;
    struct DoubleLinkStruct* next;
}Node;

void init(Node* pNode) {
    pNode->pre = pNode;
    pNode->next = pNode;
    pNode->data = NULL;
}

bool add(Node* pHead, Student data, int index) {
    if (index < 0) {
        return false;
    }
    Node* tmp = pHead->next;
    int i = 0;
    while (i < index && tmp != pHead) {
        tmp = tmp->next;
        i++;
    }
    if (i == index) {
        tmp = tmp->pre;
        Node* pNewNode = (Node*)malloc(sizeof(Node));
        pNewNode->data = (Student*)malloc(sizeof(Student));
        *(pNewNode->data) = data;

        pNewNode->next = tmp->next;
        pNewNode->pre = tmp;
        tmp->next->pre = pNewNode;
        tmp->next = pNewNode;
        return true;
    } else {
        return false;
    }
}

void printData(Student data) {
    printf("num=%d,name=%s\n", data.stuNum, data.stuName);
}

void print(Node* head) {
    Node* tmp = head->next;
    while (tmp != head) {
        printData(*(tmp->data));
        tmp = tmp->next;
    }
}
void main() {
    Node head;
    init(&head);

    printf("Start add\n");
    Student stu1;
    stu1.stuNum = 1;
    stu1.stuName = "name1";
    add(&head, stu1, 0);
    Student stu2;
    stu2.stuNum = 2;
    stu2.stuName = "name2";
    add(&head, stu2, 1);
    Student stu3;
    stu3.stuNum = 3;
    stu3.stuName = "name3";
    add(&head, stu3, 0);
    Student stu4;
    stu4.stuNum = 4;
    stu4.stuName = "name4";
    add(&head, stu4, 3);
    print(&head);
}