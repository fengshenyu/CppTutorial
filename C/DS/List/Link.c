#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
typedef int bool;

typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;

typedef struct LinkStruct{
    Student* ele;
    struct LinkStruct* next;
}Node;

void init(Node* pNode) {
    pNode->ele = NULL;
    pNode->next = NULL;
}

void addHead(Node* pHead, Student stu) {
    Node* pNode = (Node*)malloc(sizeof(Node));
    pNode->ele = (Student*)malloc(sizeof(Student));
    *(pNode->ele) = stu;
    pNode->next = pHead->next;
    pHead->next = pNode;
}

bool add(Node* pHead, int index, Student stu) {
    if (index < 0) {
        return false;
    }
    Node* tmp = pHead;
    int i = 0;
    bool found = false;
    while (tmp != NULL) {
        if (i == index) {
            found = true;
            break;
        } else {
            tmp = tmp->next;
            i++;
        }
    }
    if (found) {
        Node* pNewNode = (Node*)malloc(sizeof(Node));
        pNewNode->ele = (Student*)malloc(sizeof(Student));
        *(pNewNode->ele) = stu;
        pNewNode->next = tmp->next;
        tmp->next = pNewNode;
        return true;
    } else {
        return false;
    }
}

void clear(Node* head) {
    Node* current = head->next;
    head->next = NULL;
    Node* next;
    while(current != NULL) {
        next = current->next;
        free(current->ele);
        free(current);
        current = next;
    }
}

void print(Node head) {
    Node* temp = head.next;
    while (temp != NULL) {
        printf("num=%d,name=%s\n", temp->ele->stuNum, temp->ele->stuName);
        temp = temp->next;
    }
}

void main() {
    Node head;
    init(&head);

    printf("start add end\n");
    Student stu1;
    Student stu2;
    Student stu3;
    stu1.stuNum = 1;
    stu2.stuNum = 2;
    stu3.stuNum = 3;
    stu1.stuName = "name1";
    stu2.stuName = "name2";
    stu3.stuName = "name3";
    addHead(&head, stu1);
    addHead(&head, stu2);
    addHead(&head, stu3);
    print(head);

    printf("start add\n");
    Student stu4;
    stu4.stuNum = 4;
    stu4.stuName = "name4";
    add(&head, 0, stu4);
    Student stu5;
    stu5.stuNum = 5;
    stu5.stuName = "name5";
    add(&head, 1, stu5);
    Student stu6;
    stu6.stuNum = 6;
    stu6.stuName = "name6";
    add(&head, 5, stu6);
    print(head);

    printf("Start clear\n");
    clear(&head);
}