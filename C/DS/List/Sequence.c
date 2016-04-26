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

int getFlagIndex(char[] line, int len) {
    int flagIndex = 0;
    bool found = false;
    for (int i = 0; i < len; i++) {
        if (line[i] == ',') {
            flagIndex = i;
            found = true;
            break;
        }
    }
    return found ? flagIndex : -1;
}

char* getName(char[] line, int len) {
    int flagIndex = getFlagIndex(line, len);
    if (flagIndex == -1) {
        return -1;
    }
}

int getNum(char[] line, int len) {
    int flagIndex = getFlagIndex(line, len);
    if (flagIndex == -1) {
        return -1;
    }
    char* pNum = (char*) malloc(sizeof(char) * (flagIndex + i));
    for (int i = 0; i < flagIndex; i++) {
        *(pNum + i) = line[i];
    }
    *(pNum + flagIndex) = '\0';
    return atoi(pNum);
}

void test1() {
    char filename[] = "data.txt";
    FILE *fp; 
    char line[1024];            
    if((fp = fopen(filename,"r")) == NULL) { 
          printf("error!"); 
          return; 
    } 
    while (!feof(fp)) { 
      fgets(line, 1024, fp); 
      printf("%s", line); 
    } 
    fclose(fp);
}
void main() {
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

   // print(sequence);
   test1();
}