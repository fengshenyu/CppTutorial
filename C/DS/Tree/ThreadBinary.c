#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define TOTAL_SIZE 1000
#define MAX_SIZE 50
#define true 1
#define false 0

typedef int bool;
typedef struct StudentStruct{
    int stuNum;
    char* stuName;
}Student;
typedef enum {
    Link,Thread
}PointerTag;
typedef struct ThreadBinarySturct{
    Student data;
    struct ThreadBinarySturct* lChild;
    struct ThreadBinarySturct* rChild;
    PointerTag lTag;
    PointerTag rTag;
}ThreadBinary;
typedef struct {
    Student *ele;
    int used;
    int total;
}Sequence;

void initSequence(Sequence* pSequence) {
    Student* ele = (Student*)malloc(sizeof(Student) * TOTAL_SIZE);
    pSequence->ele = ele;
    pSequence->used = 0;
    pSequence->total = TOTAL_SIZE;
}

void initData(Student* stu, char* line, char* delim) {
    if (*line == '#') {
        stu->stuNum = -1;
        stu->stuName = NULL;
        return;
    }
    int num = atoi(strtok(line, delim));
    char* lineName = strtok(NULL, delim);
    char* name = (char*)malloc(sizeof(char) * (strlen(lineName) + 1));
    *name = '\0';
    strcat(name, lineName);

    stu->stuNum = num;
    stu->stuName = name;
}

bool addLast(Sequence* pSequence, Student stu) {
    if (pSequence->used == TOTAL_SIZE){
        return false;
    }
    *(pSequence->ele + pSequence->used) = stu;
    pSequence->used++;
    return true;
}

void initInput(Sequence* pSequence) {
    char filename[] = 
        "D:\\src\\CppTutorial\\C\\DS\\Input\\BinaryTree.input"; 
    FILE *fp; 
    if((fp = fopen(filename, "r")) == NULL) { 
          printf("error!"); 
          return;
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
        addLast(pSequence, stu);
    }
    fclose(fp); 
}

void print(Sequence sequence) {
    printf("used=%d,total=%d\n", sequence.used, sequence.total);
    for (int i = 0; i < sequence.used; i++) {
        Student student = *(sequence.ele + i);
        printf("number=%d,name=%s\n", student.stuNum, student.stuName);
    }
}

bool removeFirst(Sequence* pSequence, Student* pStu) {
    if (pSequence->used == 0) {
        return false;
    }
    Student* ele = pSequence->ele;
    *pStu = *ele;
    for (int i = 0; i <= pSequence->used - 2; i++) {
        *(ele + i) = *(ele + i + 1);
    }
    pSequence->used--;
    return true;
}

void createBinaryTree(Sequence* pSequence, ThreadBinary** tree) {
    Student stu;
    removeFirst(pSequence, &stu);
    if (stu.stuNum == -1) {
        *tree = NULL;
    } else {
        *tree = (ThreadBinary*)malloc(sizeof(ThreadBinary));
        (*tree)->data = stu;
        createBinaryTree(pSequence, &((*tree)->lChild));
        createBinaryTree(pSequence, &((*tree)->rChild));
    }
}

void inOrderPrint(ThreadBinary* pTree) {
    if (pTree != NULL) {
        inOrderPrint(pTree->lChild);
        printf("num=%d,name=%s\n", (pTree->data).stuNum, (pTree->data).stuName);
        inOrderPrint(pTree->rChild);
    }
}

int main() {
    Sequence sequence;
    initSequence(&sequence);
    initInput(&sequence);
    print(sequence);
    printf("\n");

    ThreadBinary* tree;
    createBinaryTree(&sequence, &tree);
    printf("\nInOrder:\n");
    inOrderPrint(tree);
    return 0;
}