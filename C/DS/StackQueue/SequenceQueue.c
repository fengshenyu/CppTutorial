#include <stdio.h>
#define TOTAL_SIZE 5
#define true 1
#define false 0
typedef int bool;
typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;

typedef struct SequenceQueueStruct {
    Student data[TOTAL_SIZE];
    int front;
    int rear;
}Queue;

void init(Queue* pQueue) {
    pQueue->front = 0;
    pQueue->rear = 0;
}

bool enter(Queue* pQueue, Student stu) {
    if ((pQueue->rear + 1) % TOTAL_SIZE == 0) {
        return false;
    }
    (pQueue->data)[pQueue->rear] = stu;
    pQueue->rear = (pQueue->rear + 1) % TOTAL_SIZE;
    return true;
}

bool delete(Queue* pQueue, Student* stu) {
    if (pQueue->front == pQueue->rear) {
        return false;
    }
    *stu = (pQueue->data)[pQueue->front];
    pQueue->front = (pQueue->front + 1) % TOTAL_SIZE;
    return true;
}
void printData(Student data) {
    printf("num=%d,name=%s\n", data.stuNum, data.stuName);
}

void print(Queue queue) {
    for (int i = queue.front; i != queue.rear; i = (i + 1) % TOTAL_SIZE) {
        printData((queue.data)[i]);
    }
}
void main() {
    Queue queue;
    init(&queue);

    printf("Start enter\n");
    Student stu1;
    stu1.stuNum = 1;
    stu1.stuName = "name1";
    enter(&queue, stu1);
    Student stu2;
    stu2.stuNum = 2;
    stu2.stuName = "name2";
    enter(&queue, stu2);
    Student stu3;
    stu3.stuNum = 3;
    stu3.stuName = "name3";
    enter(&queue, stu3);
    Student stu4;
    stu4.stuNum = 4;
    stu4.stuName = "name4";
    enter(&queue, stu4);
    Student stu5;
    stu5.stuNum = 5;
    stu5.stuName = "name5";
    enter(&queue, stu5);
    print(queue);
    printf("\n");

    printf("Start delete\n");
    Student stu6;
    Student stu7;
    Student stu8;
    Student stu9;
    delete(&queue, &stu6);
    delete(&queue, &stu7);
    delete(&queue, &stu8);
    delete(&queue, &stu9);
    printf("Delete:");
    printData(stu6);
    printf("Delete:");
    printData(stu7);
    printf("Delete:");
    printData(stu8);
    printf("Delete:");
    printData(stu9);
    print(queue);
}