#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
#define TOTAL_SIZE 5000

typedef int bool;
typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;
typedef struct {
    Student *ele;
    int used;
    int total;
}Sequence;

void init(Sequence* pSequence) {
    Student* ele = (Student*)malloc(sizeof(Student) * TOTAL_SIZE);
    pSequence->ele = ele;
    pSequence->used = 0;
    pSequence->total = TOTAL_SIZE;
}

void destroy(Sequence* pSequence) {
    free(pSequence->ele);
    pSequence->ele = NULL;
    pSequence->used = 0;
    pSequence->total = 0;
}

void print(Sequence sequence) {
    printf("used=%d,total=%d\n", sequence.used, sequence.total);
    for (int i = 0; i < sequence.used; i++) {
        Student student = *(sequence.ele + i);
        printf("number=%d,name=%s\n", student.stuNum, student.stuName);
    }
}

bool addEnd(Sequence* pSequence, Student stu) {
    if (pSequence->used == TOTAL_SIZE) {
        return false;
    }
    Student* startAddr = pSequence->ele;
    *(startAddr + pSequence->used) = stu;
    pSequence->used++;
    return true;
}

bool add(Sequence* pSequence, Student stu, int index) {
    if (pSequence->used == TOTAL_SIZE || index < 0 || index > pSequence->used){
        return false;
    }
    int tmpIndex = pSequence->used - 1;
    Student* p = pSequence->ele;
    while (tmpIndex >= index) {
        *(p + tmpIndex + 1) = *(p + tmpIndex);
        tmpIndex--;
    }
    *(p + index) = stu;
    pSequence->used++;
    return true;
}

bool delete(Sequence* pSequence, int index, Student* pStu) {
    if (index < 0 || index >= pSequence->used) {
        return false;
    }
    Student* ele = pSequence->ele;
    *pStu = *(ele + index);
    for (int i = index; i <= pSequence->used - 2; i++) {
        *(ele + i) = *(ele + i + 1);
    }
    pSequence->used--;
    return true;
}

bool find(Sequence sequence, int index, Student* pStu) {
    if (index < 0 || index >= sequence.used) {
        return false;
    }
    *pStu = *(sequence.ele + index);
    return true;
}

bool modify(Sequence* pSequence, int index, Student stu) {
    if (index < 0 || index >= pSequence->used) {
        return false;
    }
    *(pSequence->ele + index) = stu;
    return true;
}

bool addLast(Sequence* pSequence, Student stu) {
    if (pSequence->used == TOTAL_SIZE){
        return false;
    }
    *(pSequence->ele + pSequence->used) = stu;
    pSequence->used++;
    return true;
}

int main() {
    Sequence sequence;
    init(&sequence);

    Student stu1;
    stu1.stuNum = 1;
    stu1.stuName = "name1";
    Student stu2;
    stu2.stuNum = 2;
    stu2.stuName = "name2";
    Student stu3;
    stu3.stuNum = 3;
    stu3.stuName = "name3";
    addEnd(&sequence, stu1);
    addEnd(&sequence, stu2);
    addEnd(&sequence, stu3);

    Student stu4;
    stu4.stuNum = 4;
    stu4.stuName = "name4";
    add(&sequence, stu4, 0);
    Student stu5;
    stu5.stuNum = 5;
    stu5.stuName = "name5";
    add(&sequence, stu5, 0);
    Student stu6;
    stu6.stuNum = 6;
    stu6.stuName = "name6";
    add(&sequence, stu6, 0);
    print(sequence);

    printf("Start delete\n");
    Student stuDel;
    delete(&sequence, 0, &stuDel);
    print(sequence);
    printf("Del:num=%d,name=%s\n", stuDel.stuNum, stuDel.stuName);

    printf("Start find\n");
    Student stuFind;
    find(sequence, 1, &stuFind);
    print(sequence);
    printf("find:num=%d,name=%s\n", stuFind.stuNum, stuFind.stuName);

    printf("Start modify\n");
    Student stuModify;
    stuModify.stuNum = 100;
    stuModify.stuName = "name100";
    modify(&sequence, 2, stuModify);
    print(sequence);
    printf("\n");

    printf("Start add last.\n");
    Student stu101;
    stu101.stuNum = 101;
    stu101.stuName = "name101";
    addLast(&sequence, stu101);
    Student stu102;
    stu102.stuNum = 102;
    stu102.stuName = "name102";
    addLast(&sequence, stu102);
    print(sequence);

    destroy(&sequence);
    return 0;
}