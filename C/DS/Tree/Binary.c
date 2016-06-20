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
typedef struct BinarySturct{
    Student data;
    struct BinarySturct* lChild;
    struct BinarySturct* rChild;
}Binary;
typedef struct {
    Student *ele;
    int used;
    int total;
}Sequence;
typedef struct StackStruct {
    Binary** base;
    Binary** top;
    int size;
}Stack;

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
      "D:\\Github\\CppTutorial\\C\\DS\\Input\\BinaryTree.input";
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

void createBinaryTree(Sequence* pSequence, Binary** tree) {
    Student stu;
    removeFirst(pSequence, &stu);
    if (stu.stuNum == -1) {
        *tree = NULL;
    } else {
        *tree = (Binary*)malloc(sizeof(Binary));
        (*tree)->data = stu;
        createBinaryTree(pSequence, &((*tree)->lChild));
        createBinaryTree(pSequence, &((*tree)->rChild));
    }
}

void prePrint(Binary* pTree) {
    if (pTree != NULL) {
        printf("num=%d,name=%s\n", (pTree->data).stuNum, (pTree->data).stuName);
        prePrint(pTree->lChild);
        prePrint(pTree->rChild);
    }
}

void preOrderPrint(Binary* pTree) {
    if (pTree != NULL) {
        printf("num=%d,name=%s\n", (pTree->data).stuNum, (pTree->data).stuName);
        preOrderPrint(pTree->lChild);
        preOrderPrint(pTree->rChild);
    }
}

void inOrderPrint(Binary* pTree) {
    if (pTree != NULL) {
        inOrderPrint(pTree->lChild);
        printf("num=%d,name=%s\n", (pTree->data).stuNum, (pTree->data).stuName);
        inOrderPrint(pTree->rChild);
    }
}

void postOrderPrint(Binary* pTree) {
    if (pTree != NULL) {
        postOrderPrint(pTree->lChild);
        postOrderPrint(pTree->rChild);
        printf("num=%d,name=%s\n", (pTree->data).stuNum, (pTree->data).stuName);
    }
}

bool push(Stack* pStack, Binary* data) {
    if (pStack->top - pStack->base == TOTAL_SIZE) {
        return false;
    }
    *(pStack->top) = data;
    pStack->top++;
    return true;
}

bool pop(Stack* pStack, Binary** data) {
    if (pStack->base == pStack->top) {
        return false;
    }
    pStack->top--;
    *data = *(pStack->top);
    return true;
}

void initStack(Stack* pStack) {
    pStack->base = (Binary**)malloc(sizeof(Binary*) * TOTAL_SIZE);
    pStack->top = pStack->base;
    pStack->size = TOTAL_SIZE;
}

bool getTop(Stack* pStack, Binary** data) {
    if (pStack->base == pStack->top) {
        return false;
    }
    Binary** top = pStack->top - 1;
    *data = *top;
    return true;
}

bool isEmpty(Stack* pStack) {
    return pStack->base == pStack->top;
}

void inOrderPrintNoRecursion(Binary* pTree) {
    Stack stack;
    initStack(&stack);
    push(&stack, pTree);
    while (!isEmpty(&stack)) {
        Binary* tmp;
        while (getTop(&stack, &tmp) && (tmp != NULL)) {
            push(&stack, tmp->lChild);
        }
        pop(&stack, &tmp);
        if (!isEmpty(&stack)) {
            pop(&stack, &tmp);
            printf("num=%d,name=%s\n", (tmp->data).stuNum, (tmp->data).stuName);
            push(&stack, tmp->rChild);
        }
    }
}

void inOrderPrintNoRecursion1(Binary* pTree) {
    Stack stack;
    initStack(&stack);
    Binary* tmp = pTree;
    while (tmp != NULL || !isEmpty(&stack)) {
        if (tmp != NULL) {
            push(&stack, tmp);
            tmp = tmp->lChild;
        } else {
            pop(&stack, &tmp);
            printf("num=%d,name=%s\n", (tmp->data).stuNum, (tmp->data).stuName);
            tmp = tmp->rChild;
        }
    }
}

int main() {
    Sequence sequence;
    initSequence(&sequence);
    initInput(&sequence);
    print(sequence);
    printf("\n");

    Binary* tree;
    createBinaryTree(&sequence, &tree);
    printf("PreOrder:\n");
    preOrderPrint(tree);
    printf("\nInOrder:\n");
    inOrderPrint(tree);
    printf("\nPostOrder:\n");
    postOrderPrint(tree);
    printf("\ninOrderNoRecursion:\n");
    inOrderPrintNoRecursion(tree);

    printf("\ninOrderNoRecursion1:\n");
    inOrderPrintNoRecursion1(tree);
    return 0;
}
