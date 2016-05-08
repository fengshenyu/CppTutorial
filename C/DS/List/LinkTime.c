#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#define true 1
#define false 0
typedef int bool;
#define MAX_SIZE 50

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

void initData(Student* stu, char* line, char* delim) {
    int num = atoi(strtok(line, delim));
    char* lineName = strtok(NULL, delim);
    char* name = (char*)malloc(sizeof(char) * (strlen(lineName) + 1));
    *name = '\0';
    strcat(name, lineName);

    stu->stuNum = num;
    stu->stuName = name;
}

void main() {
    int start = clock();
    Node head;
    init(&head);
    char filename[] = 
        "D:\\IdeaPrj\\CppTutorial\\C\\DS\\DataGenerator\\string.data"; 
    FILE *fp; 
    if((fp = fopen(filename, "r")) == NULL) { 
          printf("error!"); 
    } 
    while (!feof(fp)) { 
        char strLine[MAX_SIZE] = "";
        fgets(strLine, MAX_SIZE, fp);
        int last = strlen(strLine);
        if (last == 0) {
            continue;
        }
        if (strLine[last - 1] == '\n') {
            strLine[last - 1] = '\0';
        }
        Student stu;
        initData(&stu, strLine, ",");
        addHead(&head, stu);
    }
    fclose(fp);   
    int end = clock();
    printf("Total time=%d\n", (end - start));                  
}