#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#define true 1
#define false 0
#define TOTAL_SIZE 60000
#define MAX_SIZE 50

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
    Sequence sequence;
    init(&sequence);

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
        add(&sequence, stu, 0);
    }
    fclose(fp);   
    int end = clock();
    printf("Total time=%d\n", (end - start));  
}